# tools/

Python scripts are stdlib-only. Binary tools (Ghidra, JDK) live under _local/ (gitignored) and are installed by the runbook in ghidra/.

- scaffold_from_manifest.py — seeds source/ from the ancestors per eference/manifest/FILE_MAP.md.
- layout_asserts.py — emits static_assert checks from the PDB type dump.
- check_symbol_parity.py, check_strings.py, check_no_thirdparty.py, check_status.py — QA gates.
- compare_pe.py — are two builds of one DLL the same code? Compares two PE32 images modulo linker metadata (debug directory, timestamps, moved tail data and the addresses that point at it); used to check a rebuild against `release/<date>/`.
- ghidra/ — headless decompile runbook + script.
- parity/ — lockstep A/B runbook.
