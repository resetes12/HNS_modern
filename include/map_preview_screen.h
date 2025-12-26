#ifndef GUARD_MAP_PREVIEW_SCREEN_H
#define GUARD_MAP_PREVIEW_SCREEN_H

enum MapPreviewScreenId
{
    //FRLG Kanto
    /*MPS_VIRIDIAN_FOREST,
    MPS_MT_MOON,
    MPS_DIGLETTS_CAVE,
    MPS_ROCK_TUNNEL,
    MPS_POKEMON_TOWER,
    MPS_SAFARI_ZONE,
    MPS_SEAFOAM_ISLANDS,
    MPS_POKEMON_MANSION,
    MPS_ROCKET_HIDEOUT,
    MPS_SILPH_CO,
    MPS_VICTORY_ROAD,
    MPS_CERULEAN_CAVE,
    MPS_POWER_PLANT,
    //FRLG Sevii Islands
    MPS_MT_EMBER,
    MPS_ROCKET_WAREHOUSE,
    MPS_MONEAN_CHAMBER,
    MPS_DOTTED_HOLE,
    MPS_BERRY_FOREST,
    MPS_ICEFALL_CAVE,
    MPS_LOST_CAVE,
    MPS_ALTERING_CAVE,
    MPS_PATTERN_BUSH,
    MPS_LIPTOO_CHAMBER,
    MPS_WEEPTH_CHAMBER,
    MPS_TDILFORD_CHAMBER,
    MPS_SCUFIB_CHAMBER,
    MPS_RIXY_CHAMBER,
    MPS_VIAPOIS_CHAMBER,
    MPS_SAFARI_ZONE_JOHTO,*/
    //HGSS
    MPS_HGSS_BURNED_TOWER,
    MPS_HGSS_CERULEAN_CAVE,
    MPS_HGSS_DARK_CAVE,
    MPS_HGSS_DIGGLET_CAVE,
    MPS_HGSS_DRAGON_DEN,
    MPS_HGSS_ICE_PATH,
    MPS_HGSS_ILEX_FOREST,
    MPS_HGSS_MT_MOON,
    MPS_HGSS_MT_MORTAR,
    MPS_HGSS_MT_SILVER,
    MPS_HGSS_NATIONAL_PARK,
    MPS_HGSS_ROCK_TUNNEL,
    MPS_HGSS_RUINS_OF_ALPH,
    MPS_HGSS_SEAFOAM_ISLANDS,
    MPS_HGSS_SLOWPOKE_WELL,
    MPS_HGSS_SPROUT_TOWER,
    MPS_HGSS_TIN_TOWER,
    MPS_HGSS_TOHJO_FALLS,
    MPS_HGSS_UNION_CAVE,
    MPS_HGSS_VICTORY_ROAD,
    MPS_HGSS_VIRIDIAN_FOREST,
    MPS_HGSS_WHIRL_ISLANDS,
    MPS_COUNT
};

enum PreviewImageId
{
    //FRLG
    /*IMG_VIRIDIAN_FOREST,
    IMG_MT_MOON,
    IMG_DIGLETTS_CAVE,
    IMG_ROCK_TUNNEL,
    IMG_POKEMON_TOWER,
    IMG_SAFARI_ZONE,
    IMG_SEAFOAM_ISLANDS,
    IMG_POKEMON_MANSION,
    IMG_ROCKET_HIDEOUT,
    IMG_SILPH_CO,
    IMG_VICTORY_ROAD,
    IMG_CERULEAN_CAVE,
    IMG_POWER_PLANT,
    IMG_MT_EMBER,
    IMG_ROCKET_WAREHOUSE,
    IMG_MONEAN_CHAMBER,
    IMG_DOTTED_HOLE,
    IMG_BERRY_FOREST,
    IMG_ICEFALL_CAVE,
    IMG_LOST_CAVE,
    IMG_ALTERING_CAVE,*/
    //HGSS
    IMG_HGSS_BURNED_TOWER,
    IMG_HGSS_CERULEAN_CAVE,
    IMG_HGSS_DARK_CAVE,
    IMG_HGSS_DIGGLET_CAVE,
    IMG_HGSS_DRAGON_DEN,
    IMG_HGSS_ICE_PATH,
    IMG_HGSS_ILEX_FOREST,
    IMG_HGSS_MT_MOON,
    IMG_HGSS_MT_MORTAR,
    IMG_HGSS_MT_SILVER, //
    IMG_HGSS_NATIONAL_PARK,
    IMG_HGSS_ROCK_TUNNEL,
    IMG_HGSS_RUINS_OF_ALPH,
    IMG_HGSS_SEAFOAM_ISLANDS,
    IMG_HGSS_SLOWPOKE_WELL,
    IMG_HGSS_SPROUT_TOWER,
    IMG_HGSS_TIN_TOWER,
    IMG_HGSS_TOHJO_FALLS,
    IMG_HGSS_UNION_CAVE,
    IMG_HGSS_VICTORY_ROAD,
    IMG_HGSS_VIRIDIAN_FOREST,
    IMG_HGSS_WHIRL_ISLANDS,
    IMG_COUNT
};

// Map Preview Configs
#define MPS_DURATION_LONG       120 // This is the number of frames the map preview will last when the player enters the map for the first time.

#define MPS_DURATION_SHORT      40  // This is the number of frames the map preview will last if the player has visited the map before.

#define MPS_DURATION_NO_FLAG    40  // This is the number of frames the map preview will last if the map's flagId is MPS_FLAG_NULL.

#define MPS_DURATION_ALWAYS     80   // If this number is not 0, MPS_DURATION_ALWAYS will override all other duration values.
                                    // For example, if you set MPS_DURATION_ALWAYS to 100, the map preview will always
                                    // have a duration of 100 frames every time, regardless of the flag state.

#define MPS_DURATION_SCRIPT     120 // This is the number of frames the map preview will last when it is called
                                    // with the mappreview scripting macro.
                                    // It is unaffected by MPS_DURATION_ALWAYS.

#define MPS_BASIC_FADE_SPEED    1   // This sets the speed that the map preview fades out when MPS_TYPE_BASIC is used.
                                    // Numbers less than 1 will have a shorter fade time (negative numbers can be used).
                                    // Numbers greater than 1 will have a longer fade time.


// Constants
#define MPS_TYPE_BASIC      0
#define MPS_TYPE_FADE_IN    1
#define MPS_TYPE_CAVE       2
#define MPS_TYPE_ANY        3

#define MPS_FLAG_NULL       0

struct MapPreviewScreen
{
    u8 mapsec;
    u8 type;
    u16 flagId;
    u8 image;
};

struct ImageData
{
    const void *tilesptr;
    const void *tilemapptr;
    const void *palptr;
};

u16 MapPreview_CreateMapNameWindow(u8 id);
u16 MapPreview_GetDuration(u8 id);
bool8 MapHasPreviewScreen(u8 mapsec, u8 type);
bool32 ForestMapPreviewScreenIsRunning(void);
const struct MapPreviewScreen * GetDungeonMapPreviewScreenInfo(u8 mapsec);
bool32 MapHasPreviewScreen_HandleQLState2(u8 mapsec, u8 type);
void MapPreview_InitBgs(void);
void MapPreview_LoadGfx(u8 mapsec);
bool32 MapPreview_IsGfxLoadFinished(void);
void MapPreview_Unload(s32 windowId);
void MapPreview_StartForestTransition(u8 mapsec);

#endif //GUARD_MAP_PREVIEW_SCREEN_H
