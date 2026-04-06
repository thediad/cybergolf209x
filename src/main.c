#include <genesis.h>
#include "cutscene.h"
#include "resources.h"

const u8 cg_scene_durations[CG_SCENES] = {8, 8, 8, 8, 8, 8}; // default ~48s total

static void wait_seconds(u16 seconds)
{
    u32 frames = (u32)seconds * 60u; // SGDK typical ~60 FPS
    while (frames--)
    {
        SYS_doVBlankProcess();
    }
}

static void show_scene_title(const char* title)
{
    VDP_clearText(0, 0, 40);
    VDP_drawText(title, 10, 13);
}

static void scene_0(void)
{

    show_scene_title("Scene 1: NEON FAIRWAYS");

    PAL_setPalette(PAL0, scene1.palette->data, DMA);
    VDP_drawImage(BG_B, &scene1, 4, 4);



    // Placeholder: scene rendering will be implemented later.
    // Current behavior: wait for the configured duration for this scene.
    wait_seconds(cg_scene_durations[0]);
}

static void scene_1(void)
{
    show_scene_title("Scene 2: THE WARRIORS");
    wait_seconds(cg_scene_durations[1]);
}

static void scene_2(void)
{
    show_scene_title("Scene 3: MEGACORPS");
    wait_seconds(cg_scene_durations[2]);
}

static void scene_3(void)
{
    show_scene_title("Scene 4: THE INCIDENT(?)");
    wait_seconds(cg_scene_durations[3]);
}

static void scene_4(void)
{
    show_scene_title("Scene 5: THE HERO");
    wait_seconds(cg_scene_durations[4]);
}

static void scene_5(void)
{
    show_scene_title("Scene 6: TITLE SCREEN DROP");
    wait_seconds(cg_scene_durations[5]);
}

void CG_playCutscene(void)
{
    void (*scenes[CG_SCENES])(void) = {scene_0, scene_1, scene_2, scene_3, scene_4, scene_5};

    for (int i = 0; i < CG_SCENES; ++i)
    {
        scenes[i]();
        // small transition pause
        wait_seconds(1);
    }
}

int main(bool hardReset)
{
    SYS_disableInts();
    VDP_setTextPalette(PAL0);
    VDP_clearPlane(BG_A, TRUE);
    VDP_clearPlane(BG_B, TRUE);

    SYS_enableInts();

    while (TRUE)
    {
        CG_playCutscene();

        // After cutscene, loop back and pause briefly
        wait_seconds(3);
    }

    return 0;
}
