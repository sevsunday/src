# build/

`build.cmd` is the only build entry point. `build.cmd check` runs the mechanical QA gates.
Output: `../out/Win32/Release/bin/missions/*.dll` (gitignored). GBD's own output folder was
`Build\\Win32\\Release\\bin\\missions`; on NTFS that name would be this very folder (case-insensitive),
so the output root is `out/`.

`stub/stub_strategy02.cpp` is the task-4 toolchain proof: a minimal Strategy02.dll exporting
`GetMisnAPI` with the version magic. Built by `build.cmd stub` into `out/Win32/Release/bin/stub/`.
It is not part of the reconstruction.
