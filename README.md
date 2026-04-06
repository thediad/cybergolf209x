Cyber Golf 209X — Cutscene Demo

Short SGDK demo project that plays a 6-scene cutscene for "Cyber Golf 209X".

- Scenes: 6
- Target runtime: ~40-60 seconds total (each scene ~6–12s)

Structure:
- `src/` — C source files (entry point and cutscene logic)
- `inc/` — headers
- `res/` — resources (images/audio). Add assets here and run the SGDK resource compiler (`rescomp`) to generate `resources.h`.

Build:
Use the workspace make system (root `makefile.gen`). From the project root run the SGDK build task or use the provided VS Code tasks.

Notes:
- This project contains placeholder text and waits for each scene. Replace or expand scene functions in `src/main.c` to add images/sprite animations, music, and transitions.
