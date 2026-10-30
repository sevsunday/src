# original/missions/ — the shipped binaries (Tier A)

Source: BlackDragonN001/VSR_Workshop commit 58a5f56c308c152ab25acb8470429351c44eb713 (master, 2026-10-18),
path Upload/VSR/Missions/. Exported 2026-10-28 with git archive; every file's git blob hash
was re-checked after export. The same eight files are byte-identical to the live Steam Workshop
install (steamapps/workshop/content/624970/1325933293/VSR/Missions/) on the same date.

| File | Bytes | Link time (UTC) | Notes |
|---|---:|---|---|
| Strategy02.dll   | 465,408   | 2026-02-20 16:26:59 | PE32 x86, single export GetMisnAPI, no VERSIONINFO |
| Strategy02.pdb   | 3,739,648 | | embedded path E:\Github\VSR_DLL_Source\Build\Win32\Release\bin\missions\Strategy02.pdb |
| LuaMission.dll   | 433,152   | 2026-02-20 16:26:58 | |
| LuaMission.pdb   | 3,477,504 | | |
| Instant.dll      | 445,952   | 2026-02-20 16:26:59 | |
| Instant.pdb      | 3,526,656 | | |
| deathmatch01.dll | 449,536   | 2026-02-20 16:26:59 | |
| deathmatch01.pdb | 3,575,808 | | |

The link timestamps match Workshop commit d0f63c6 (2026-02-20, "Fixed bug in Service Truck AI
Dispatch code"), the latest DLL build in the repository's history.

Verify: compare Get-FileHash * -Algorithm SHA256 with SHA256SUMS.txt (sha256sum format).