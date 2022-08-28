#include <stdio.h>

#include <libdragon.h>

#include <stdlib.h>

int main(void)
{
    console_init();
    debug_init_usblog();
    console_set_debug(true);
    display_init(   RESOLUTION_320x240, DEPTH_32_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE_FETCH_ALWAYS  );
    dfs_init(DFS_DEFAULT_LOCATION);
    rdp_init();
    controller_init();
    timer_init();

    //title screen
    int fp = dfs_open("/gfx/title.sprite");
    sprite_t *title_screen = malloc(dfs_size(fp));
    dfs_read(title_screen, 1, dfs_size(fp), fp);
    dfs_close(fp);

    while(1) {
        static display_context_t disp = 0;
        while(!(disp = display_lock()) );
        display_show(disp);
        graphics_draw_sprite(disp, 0, 0, title_screen);
    }
}
