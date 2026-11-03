# rrgmcextension: a module with an extension point

This sample shows how a module lets an app replace part of its code when the app builds Mirante. Its item is a card with a title and a text. The module draws the title itself. The card's body comes from an **extension point**, `body`, which an app can fill with code of its own. See [extension points](https://github.com/rrgmc/mirante-core/blob/master/docs/modules.md#extension-points) in the core.

## How it works

1. **The interface.** `CardBody.h` declares what the point needs: a function `makeCardBody()` that makes the body widget from the card's title and text. Its object name must be `cardBody`.
2. **The default.** `DefaultCardBody.cpp` implements it, as a plain label.
3. **The declaration.** `CMakeLists.txt` names the point and its default: `EXTENSIONS body=DefaultCardBody.cpp`. `DefaultCardBody.cpp` is not in `SOURCES`, because it is compiled only when no extension replaces it.
4. **An extension.** [`../extensions/rrgmcextension-quote`](../extensions/rrgmcextension-quote) implements `makeCardBody()` again, as an italic quote beside an icon. It includes `CardBody.h` by name, because the module's folder is on its include path. Its `resources.txt` lists `quote.svg`, which the module then serves as `:/modules/rrgmcextension/quote.svg`.
5. **The manifest.** An app names the extension in the module's folder entry. This repository's own build does, in `ci/manifest.json`:

   ```json
   {
     "folder": "rrgmcextension",
     "extensions": { "body": { "local": "extensions/rrgmcextension-quote" } }
   }
   ```

   `local` is a folder of the app's own repository. An extension in another repository is named with `name`, `repo`, `ref` and `folder` instead. Without `extensions`, the module builds with its default.

The About dialog lists the extension as `rrgmcextension/body`, with its repository and commit.

## What an extension may do

An extension is compiled into the module, so it has the module's reach, and the same rules: its own files, the module's headers, the module interface and Qt. `build-app.yml` checks its includes. A module that offers an extension point treats the point's header as an interface that others build against, and says when it changes.

## Item types

| Id | Name | Rendering | Description |
|---|---|---|---|
| `rrgmcextension.card` | Sample card | native | A card whose body an app can replace when it builds Mirante. |

## Configuration

| Key | Type | Description |
|---|---|---|
| `title` | Text | Shown in bold at the top. Default: "A sample card". |
| `text` | Multi-line text | Shown by the body. |

## Extension points

| Point | Interface | Default |
|---|---|---|
| `body` | `makeCardBody()` in `CardBody.h` | `DefaultCardBody.cpp`, a label |

## Tests

- `tests/tst_body.cpp` checks the body from whichever implementation the build compiled in. This repository's build compiles the quote extension, so its CI tests that one.
- `tests/tst_register.cpp` registers the module and checks its type.
- `tests/tst_translations.cpp` checks that the Portuguese translation is compiled in.
