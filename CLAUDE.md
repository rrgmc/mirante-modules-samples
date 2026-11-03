# Mirante module samples

Sample modules of Mirante, one per folder, in Qt 6 (C++17, Qt Widgets, CMake), for authors outside the project. The design documents, the module interface and the guide for authors are in `mirante-core`: see its `docs/modules.md` and `docs/writing-a-module.md`.

## Git workflow

Each piece of work happens in its own Git worktree, with its own branch. Never edit files in the main checkout on `master` directly.

Changes reach `master` only through a pull request. Never merge a pull request on your own: only the user merges. When the user asks for the merge, use a merge commit (`gh pr merge <number> --merge`).

## Rules

- Each sample shows one thing, with the least code that does it, and its README explains how it works.
- A sample follows the rules of `docs/writing-a-module.md`, as an outside author would: its id starts with `rrgmc`, and it includes only its own files and `<mirante/...>`.
- Keep platform-specific code out of samples. They must build on Windows, macOS and Linux.
