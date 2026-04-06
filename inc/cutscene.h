#ifndef CYBER_GOLF_CUTSCENE_H
#define CYBER_GOLF_CUTSCENE_H

#define CG_SCENES 6

// Desired approximate durations (seconds) per scene; tune in code as needed.
extern const u8 cg_scene_durations[CG_SCENES];

void CG_playCutscene(void);

#endif // CYBER_GOLF_CUTSCENE_H
