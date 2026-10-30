# third_party/

- `lua-5.2.4/` — Lua 5.2.4, pristine from `https://www.lua.org/ftp/lua-5.2.4.tar.gz`
  (SHA-256 `b9e2e4aad6789b3b63a056d442f7b39f0ecfca3ae0f1fc0ae4e9614401b69f4b`, matches lua.org's
  published hash). MIT license (`doc/readme.html`). D6 in `../DEPENDENCIES.md`. `SHA256SUMS.txt`
  inside the folder lists the tarball and every extracted file; it is the only file we added.

Why 5.2.4: the DLLs embed `"Lua 5.2"` and export 92 Lua C-API symbols; all 92 are declared in
5.2.4's `lua.h` / `lauxlib.h` / `lualib.h` (checked 2026-10-28 against
`reference/manifest/lua_api_Strategy02.tsv`). GBD linked the BZCC engine tree's bundled Lua
(`lua51_lib.lib` by name); 5.2.4 is the final public 5.2 release.