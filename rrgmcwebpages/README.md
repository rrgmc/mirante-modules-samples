# rrgmcwebpages: a module with its own web pages

This sample shows how a module ships web pages inside itself and shows them in an item, with no HTTP server and no open port. The page lives in the module's resources, and the app serves it on the `module://` scheme. See [module pages](https://github.com/rrgmc/mirante-core/blob/master/docs/web-views.md#module-pages) in the core.

## How it works

1. **The files.** `web/index.html`, `web/page.js`, `web/page.css` and `web/greetings.json` are listed in `RESOURCES` in `CMakeLists.txt`. The build compiles them in as `:/modules/rrgmcwebpages/web/<path>`.
2. **The address.** The core serves `module://rrgmcwebpages/<path>` from that resource. The page's address is `module://rrgmcwebpages/index.html`.
3. **The view.** The item type returns `context.createWebView(url, parent)` from `createView()`. The core makes the web view, in the item's profile, with its toolbar.
4. **Data from the item.** `pageUrl()` puts the item's title in the address's query. The page reads it from `location.search`.
5. **Data from the module.** The page reads `greetings.json` with `fetch`. The scheme allows `fetch` of the module's own files.
6. **Storage.** The page keeps a count in `localStorage`, which survives a restart of the app.

## What the page may do

The core sends a Content-Security-Policy with every file of the scheme:

- The page can load files of its own module only. It cannot load scripts from the web, or call another site with `fetch`.
- Inline scripts and inline styles do not run, so the script and the style are files of their own.
- Each module has its own origin, `module://<module id>`, so its storage is its own. A page of another module, or a site in the same profile, cannot read it.
- Cookies do not work on the scheme, and a page cannot get data from the module's C++ code yet. Only files are served.

The page sets its text with `textContent`, never as markup.

## Item types

| Id | Name | Rendering | Description |
|---|---|---|---|
| `rrgmcwebpages.page` | Sample page | web | A web page that comes with the module, served without a server. |

## Configuration

| Key | Type | Description |
|---|---|---|
| `title` | Text | Shown at the top of the page. Default: "Hello from a module page". |

## Settings

None.

## Tests

- `tests/tst_register.cpp` registers the module and checks its type.
- `tests/tst_pages.cpp` checks the page's address and that every file the page uses is compiled in.
- `tests/tst_translations.cpp` checks that the Portuguese translation is compiled in.

Loading the page itself needs Qt WebEngine and the core, so the core's own `tst_module_scheme` tests that.

## Texts

The module's texts, such as the type's name and the field's label, are translated in `translations/`. The page's texts are in English only.
