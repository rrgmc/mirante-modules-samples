# Mirante module samples

Small sample modules for [Mirante](https://github.com/rrgmc/mirante), a personal desktop dashboard. Each one shows one thing a module can do, with the least code that does it. Read them beside [writing a module](https://github.com/rrgmc/mirante-core/blob/master/docs/writing-a-module.md) in the core.

| Sample | Shows |
|---|---|
| [`rrgmcwebpages`](rrgmcwebpages) | A web page that comes with the module, served by the app without an HTTP server |

## Trying a sample

Add it to the `mirante.json` of an app made from [`mirante-app-template`](https://github.com/rrgmc/mirante-app-template):

```json
{
  "name": "mirante_modules_samples",
  "repo": "https://github.com/rrgmc/mirante-modules-samples",
  "ref": "<a commit of this repository>",
  "folders": ["rrgmcwebpages"]
}
```

Or build this repository on its own, which makes the whole app with the samples in it:

```sh
cmake --preset dev -DCMAKE_PREFIX_PATH=<Qt folder>
cmake --build --preset dev
ctest --preset dev
```

Then start `build/dev/bin/mirante` with folders of its own, so it does not touch your data:

```sh
build/dev/bin/mirante --settings try/settings.ini --web-data try/web-data --no-keychain
```

Make an item of the sample's type in any task. [Building and testing](https://github.com/rrgmc/mirante-core/blob/master/docs/writing-a-module.md#building-and-testing) in the guide says what Windows needs.

## Ids

A third-party module's id starts with its owner's name, so these start with `rrgmc`. Use your own GitHub name when you copy one. See [choose an id](https://github.com/rrgmc/mirante-core/blob/master/docs/writing-a-module.md#choose-an-id).

## License

Released under the [MIT License](LICENSE). Copy any of the code into your own modules.
