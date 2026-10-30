# original/shell/ — the VSR lobby shell pages (Tier A)

Source: BlackDragonN001/VSR_Workshop commit 58a5f56c308c152ab25acb8470429351c44eb713
(D1 `master`), folder `Upload/VSR/Config/Shell/`, every file whose name starts with
`bzshell_multi` — 47 files, 779,962 bytes. Exported 2026-10-30 with `git cat-file blob`
(byte-exact; every blob hash re-checked against the commit, all 47 match). `SHA256SUMS.txt`
lists them. The other `Shell/` files at that commit (`RecDesc*.txt`, `bzshell_*` pages that
do not bind netvars) are not copied.

## Why they are here

The lobby UI is a `.cfg` page per game mode; a map's `.inf` picks the page with `svar7`
(`svar7="VSRst"` → `bzshell_multi_VSRst.cfg` on the host, `bzshell_multi_client_VSRst.cfg`
on a client; `original/docs/VSR Documents/VSR Map Info/Map inf vars.txt`). Each page binds
its controls to `network.session.ivarN` / `svarN`, so these files are the authority for
**which lobby option writes which netvar** — the `S:` tier of `docs/NETVARS.md`
(`S:<cfg>:<line>`). With the pages in the repository every `S:` citation can be checked
without cloning the Workshop repository.

## The matrix

| Suffix | Mode | Host page | Client page |
|---|---|---|---|
| `VSRst` | team strategy | `bzshell_multi_VSRst.cfg` (+ `_VSRst2.cfg`) | `bzshell_multi_client_VSRst.cfg` (+ `_client_VSRst2.cfg`) |
| `VSRstonly` | team strategy, VSR recyclers only | `bzshell_multi_VSRstonly.cfg` | `bzshell_multi_client_VSRstonly.cfg` |
| `VSRstcap` / `VSRstcaponly` | ST: Capture (`ivar53 = 4`, `ivar54` capture time) | `bzshell_multi_VSRstcap*.cfg` | `bzshell_multi_client_VSRstcap*.cfg` |
| `VSRstmpi` / `VSRstmpionly` | team strategy vs CPU (MPI, `ivar12`) | `bzshell_multi_VSRstmpi*.cfg` (+ `_VSRstmpi2/3.cfg`) | `bzshell_multi_client_VSRstmpi*.cfg` (+ `_client_VSRstmpi2/3.cfg`) |
| `VSRffa` / `VSRffaonly` | free-for-all strategy (`_VSRffa2.cfg` is the per-slot ally `ivar35-49` / thug `ivar81-94` page; `_VSRffa3.cfg` binds `ivar7`, `ivar121`, `svar5` like `_VSRst2.cfg`) | `bzshell_multi_VSRffa*.cfg` | `bzshell_multi_client_VSRffa*.cfg` |
| `VSRffacap` / `VSRffacaponly` | FFA Capture | `bzshell_multi_VSRffacap*.cfg` | `bzshell_multi_client_VSRffacap*.cfg` |
| `VSRffampi` / `VSRffampionly` | FFA vs CPU (`_VSRffampi2/3/4.cfg` sub-pages) | `bzshell_multi_VSRffampi*.cfg` | `bzshell_multi_client_VSRffampi*.cfg` |
| — | extra options page shared by the modes | `bzshell_multi_addm.cfg` | `bzshell_multi_client_addm.cfg` |
| — | stock pages VSR ships modified | `bzshell_multi_option.cfg`, `bzshell_multi_vehicle.cfg`, `bzshell_multi_chat.cfg` | |
| — | the mode-selection help text | `bzshell_multi_help_vsrmodes.cfg` / `.txt` | |

A `*2.cfg` / `*3.cfg` / `*4.cfg` file is a further options window (`CreateControl("ExtraOptions2", …)`,
`ExtraOptions3`, `ExtraOptions4`; the base page's own extra window is `ExtraOptions` in `*_addm.cfg`),
`Exec`'d from the end of its parent page (e.g. `bzshell_multi_client_VSRst.cfg:919` →
`bzshell_multi_client_VSRst2.cfg`).

Pages `docs/NETVARS.md` cites by line: `bzshell_multi_VSRst.cfg`, `bzshell_multi_client_VSRffa2.cfg`,
`bzshell_multi_addm.cfg`, `bzshell_multi_client_addm.cfg`, `bzshell_multi_option.cfg`.

The files are stored with LF line endings, as they are in GBD's repository; `original/**` is
`-text` in `.gitattributes`, so git never rewrites them.
