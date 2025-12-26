#include "global.h"
#include "string_util.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "region_map.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "script.h"
#include "overworld.h"
#include "event_data.h"
#include "map_preview_screen.h"
#include "constants/region_map_sections.h"
#include "constants/rgb.h"
#include "io_reg.h"
#include "gba/io_reg.h"


static EWRAM_DATA bool8 sAllocedBg0TilemapBuffer = FALSE;

static void Task_RunMapPreviewScreenForest(u8 taskId);
static void Task_RunMapPreview_Script(u8 taskId);
static void CB2_MapPreviewScript(void);
static void VblankCB_MapPreviewScript(void);

/*static const u8 sViridianForestMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/viridian_forest/tiles.gbapal");
static const u8 sViridianForestMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/viridian_forest/tiles.4bpp.lz");
static const u8 sViridianForestMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/viridian_forest/tilemap.bin.lz");
static const u8 sRockTunnelMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/rock_tunnel/tiles.gbapal");
static const u8 sRockTunnelMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/rock_tunnel/tiles.4bpp.lz");
static const u8 sRockTunnelMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/rock_tunnel/tilemap.bin.lz");
static const u8 sRocketHideoutMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/rocket_hideout/tiles.gbapal");
static const u8 sRocketHideoutMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/rocket_hideout/tiles.4bpp.lz");
static const u8 sRocketHideoutMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/rocket_hideout/tilemap.bin.lz");
static const u8 sPowerPlantMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/power_plant/tiles.gbapal");
static const u8 sPowerPlantMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/power_plant/tiles.4bpp.lz");
static const u8 sPowerPlantMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/power_plant/tilemap.bin.lz");
static const u8 sPokemonMansionMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/pokemon_mansion/tiles.gbapal");
static const u8 sPokemonMansionMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/pokemon_mansion/tiles.4bpp.lz");
static const u8 sPokemonMansionMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/pokemon_mansion/tilemap.bin.lz");
static const u8 sPokemonTowerMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/pokemon_tower/tiles.gbapal");
static const u8 sPokemonTowerMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/pokemon_tower/tiles.4bpp.lz");
static const u8 sPokemonTowerMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/pokemon_tower/tilemap.bin.lz");
static const u8 sSilphCoMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/silph_co/tiles.gbapal");
static const u8 sSilphCoMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/silph_co/tiles.4bpp.lz");
static const u8 sSilphCoMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/silph_co/tilemap.bin.lz");
static const u8 sMtMoonMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/mt_moon/tiles.gbapal");
static const u8 sMtMoonMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/mt_moon/tiles.4bpp.lz");
static const u8 sMtMoonMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/mt_moon/tilemap.bin.lz");
static const u8 sSeafoamIslandsMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/seafoam_islands/tiles.gbapal");
static const u8 sSeafoamIslandsMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/seafoam_islands/tiles.4bpp.lz");
static const u8 sSeafoamIslandsMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/seafoam_islands/tilemap.bin.lz");
static const u8 sRocketWarehouseMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/rocket_warehouse/tiles.gbapal");
static const u8 sRocketWarehouseMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/rocket_warehouse/tiles.4bpp.lz");
static const u8 sRocketWarehouseMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/rocket_warehouse/tilemap.bin.lz");
static const u8 sVictoryRoadMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/victory_road/tiles.gbapal");
static const u8 sVictoryRoadMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/victory_road/tiles.4bpp.lz");
static const u8 sVictoryRoadMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/victory_road/tilemap.bin.lz");
static const u8 sMtEmberMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/mt_ember/tiles.gbapal");
static const u8 sMtEmberMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/mt_ember/tiles.4bpp.lz");
static const u8 sMtEmberMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/mt_ember/tilemap.bin.lz");
static const u8 sSafariZoneMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/safari_zone/tiles.gbapal");
static const u8 sSafariZoneMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/safari_zone/tiles.4bpp.lz");
static const u8 sSafariZoneMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/safari_zone/tilemap.bin.lz");
static const u8 sMoneanChamberMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/monean_chamber/tiles.gbapal");
static const u8 sMoneanChamberMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/monean_chamber/tiles.4bpp.lz");
static const u8 sMoneanChamberMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/monean_chamber/tilemap.bin.lz");
static const u8 sDottedHoleMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/dotted_hole/tiles.gbapal");
static const u8 sDottedHoleMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/dotted_hole/tiles.4bpp.lz");
static const u8 sDottedHoleMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/dotted_hole/tilemap.bin.lz");
static const u8 sCeruleanCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/cerulean_cave/tiles.gbapal");
static const u8 sCeruleanCaveMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/cerulean_cave/tiles.4bpp.lz");
static const u8 sCeruleanCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/cerulean_cave/tilemap.bin.lz");
static const u8 sDiglettsCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/digletts_cave/tiles.gbapal");
static const u8 sDiglettsCaveMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/digletts_cave/tiles.4bpp.lz");
static const u8 sDiglettsCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/digletts_cave/tilemap.bin.lz");
static const u8 sLostCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/lost_cave/tiles.gbapal");
static const u8 sLostCaveMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/lost_cave/tiles.4bpp.lz");
static const u8 sLostCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/lost_cave/tilemap.bin.lz");
static const u8 sBerryForestMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/berry_forest/tiles.gbapal");
static const u8 sBerryForestMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/berry_forest/tiles.4bpp.lz");
static const u8 sBerryForestMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/berry_forest/tilemap.bin.lz");
static const u8 sIcefallCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/icefall_cave/tiles.gbapal");
static const u8 sIcefallCaveMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/icefall_cave/tiles.4bpp.lz");
static const u8 sIcefallCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/icefall_cave/tilemap.bin.lz");
static const u8 sAlteringCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/frlg/altering_cave/tiles.gbapal");
static const u8 sAlteringCaveMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/frlg/altering_cave/tiles.4bpp.lz");
static const u8 sAlteringCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/frlg/altering_cave/tilemap.bin.lz");*/

//hgss

static const u8 sBurnedTowerMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/burned_tower/tiles.gbapal");
static const u8 sBurnedTowerMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/burned_tower/tiles.4bpp.lz");
static const u8 sBurnedTowerMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/burned_tower/tilemap.bin.lz");

static const u8 sCeruleanCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/cerulean_cave/tiles.gbapal");
static const u8 sCeruleanCaveMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/cerulean_cave/tiles.4bpp.lz");
static const u8 sCeruleanCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/cerulean_cave/tilemap.bin.lz");

static const u8 sDarkCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/dark_cave/tiles.gbapal");
static const u8 sDarkCaveMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/dark_cave/tiles.4bpp.lz");
static const u8 sDarkCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/dark_cave/tilemap.bin.lz");

static const u8 sDiggletCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/digglet_cave/tiles.gbapal");
static const u8 sDiggletCaveMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/digglet_cave/tiles.4bpp.lz");
static const u8 sDiggletCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/digglet_cave/tilemap.bin.lz");

static const u8 sDragonsDenMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/dragon_den/tiles.gbapal");
static const u8 sDragonsDenMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/dragon_den/tiles.4bpp.lz");
static const u8 sDragonsDenMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/dragon_den/tilemap.bin.lz");

static const u8 sIcePathMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/ice_path/tiles.gbapal");
static const u8 sIcePathMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/ice_path/tiles.4bpp.lz");
static const u8 sIcePathMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/ice_path/tilemap.bin.lz");

static const u8 sIlexForestMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/ilex_forest/tiles.gbapal");
static const u8 sIlexForestMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/ilex_forest/tiles.4bpp.lz");
static const u8 sIlexForestMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/ilex_forest/tilemap.bin.lz");

static const u8 sMtMoonMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/mt_moon/tiles.gbapal");
static const u8 sMtMoonMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/mt_moon/tiles.4bpp.lz");
static const u8 sMtMoonMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/mt_moon/tilemap.bin.lz");

static const u8 sMtMortarMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/mt_mortar/tiles.gbapal");
static const u8 sMtMortarMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/mt_mortar/tiles.4bpp.lz");
static const u8 sMtMortarMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/mt_mortar/tilemap.bin.lz");

static const u8 sMtSilverMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/mt_silver/tiles.gbapal");
static const u8 sMtSilverMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/mt_silver/tiles.4bpp.lz");
static const u8 sMtSilverMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/mt_silver/tilemap.bin.lz");

static const u8 sNationalParkMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/national_park/tiles.gbapal");
static const u8 sNationalParkMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/national_park/tiles.4bpp.lz");
static const u8 sNationalParkMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/national_park/tilemap.bin.lz");

static const u8 sRockTunnelMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/rock_tunnel/tiles.gbapal");
static const u8 sRockTunnelMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/rock_tunnel/tiles.4bpp.lz");
static const u8 sRockTunnelMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/rock_tunnel/tilemap.bin.lz");

static const u8 sRuinsOfAlphMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/ruins_of_alph/tiles.gbapal");
static const u8 sRuinsOfAlphMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/ruins_of_alph/tiles.4bpp.lz");
static const u8 sRuinsOfAlphMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/ruins_of_alph/tilemap.bin.lz");

static const u8 sSeafoamIslandsMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/seafoam_islands/tiles.gbapal");
static const u8 sSeafoamIslandsMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/seafoam_islands/tiles.4bpp.lz");
static const u8 sSeafoamIslandsMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/seafoam_islands/tilemap.bin.lz");

static const u8 sSlowpokeWellMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/slowpoke_well/tiles.gbapal");
static const u8 sSlowpokeWellMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/slowpoke_well/tiles.4bpp.lz");
static const u8 sSlowpokeWellMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/slowpoke_well/tilemap.bin.lz");

static const u8 sSproutTowerMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/sprout_tower/tiles.gbapal");
static const u8 sSproutTowerMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/sprout_tower/tiles.4bpp.lz");
static const u8 sSproutTowerMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/sprout_tower/tilemap.bin.lz");

static const u8 sTinTowerMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/tin_tower/tiles.gbapal");
static const u8 sTinTowerMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/tin_tower/tiles.4bpp.lz");
static const u8 sTinTowerMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/tin_tower/tilemap.bin.lz");

static const u8 sTohjoFallsMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/tohjo_falls/tiles.gbapal");
static const u8 sTohjoFallsMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/tohjo_falls/tiles.4bpp.lz");
static const u8 sTohjoFallsMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/tohjo_falls/tilemap.bin.lz");

static const u8 sUnionCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/union_cave/tiles.gbapal");
static const u8 sUnionCaveMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/union_cave/tiles.4bpp.lz");
static const u8 sUnionCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/union_cave/tilemap.bin.lz");

static const u8 sVictoryRoadMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/victory_road/tiles.gbapal");
static const u8 sVictoryRoadMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/victory_road/tiles.4bpp.lz");
static const u8 sVictoryRoadMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/victory_road/tilemap.bin.lz");

static const u8 sViridianForestMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/viridian_forest/tiles.gbapal");
static const u8 sViridianForestMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/viridian_forest/tiles.4bpp.lz");
static const u8 sViridianForestMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/viridian_forest/tilemap.bin.lz");

static const u8 sWhirlIslandsMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/hgss/whirl_islands/tiles.gbapal");
static const u8 sWhirlIslandsMapPreviewTiles[]   = INCBIN_U8("graphics/map_preview/hgss/whirl_islands/tiles.4bpp.lz");
static const u8 sWhirlIslandsMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/hgss/whirl_islands/tilemap.bin.lz");

// If you set flagId to MPS_FLAG_NULL, it will not set a flag when visiting the map for the first time
// and the duration will default to MPS_DURATION_NO_FLAG.
static const struct MapPreviewScreen sMapPreviewScreenData[MPS_COUNT] = {
    //Kanto
    /*[MPS_VIRIDIAN_FOREST] = {
        .mapsec = MAPSEC_VIRIDIAN_FOREST,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_VIRIDIAN_FOREST
    },
    [MPS_MT_MOON] = {
        .mapsec = MAPSEC_MT_MOON,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MT_MOON
    },
    [MPS_DIGLETTS_CAVE] = {
        .mapsec = MAPSEC_DIGLETTS_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_DIGLETTS_CAVE
    },
    [MPS_ROCK_TUNNEL] = {
        .mapsec = MAPSEC_ROCK_TUNNEL,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_ROCK_TUNNEL
    },
    [MPS_POKEMON_TOWER] = {
        .mapsec = MAPSEC_POKEMON_TOWER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_POKEMON_TOWER
    },
    [MPS_SAFARI_ZONE] = {
        .mapsec = MAPSEC_KANTO_SAFARI_ZONE,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_SAFARI_ZONE
    },
    [MPS_SEAFOAM_ISLANDS] = {
        .mapsec = MAPSEC_SEAFOAM_ISLANDS,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_SEAFOAM_ISLANDS
    },
    [MPS_POKEMON_MANSION] = {
        .mapsec = MAPSEC_POKEMON_MANSION,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_POKEMON_MANSION
    },
    [MPS_ROCKET_HIDEOUT] = {
        .mapsec = MAPSEC_ROCKET_HIDEOUT,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_ROCKET_HIDEOUT
    },
    [MPS_SILPH_CO] = {
        .mapsec = MAPSEC_SILPH_CO,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_SILPH_CO
    },
    [MPS_VICTORY_ROAD] = {
        .mapsec = MAPSEC_VICTORY_ROAD,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_VICTORY_ROAD
    },
    [MPS_CERULEAN_CAVE] = {
        .mapsec = MAPSEC_CERULEAN_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_CERULEAN_CAVE
    },
    [MPS_POWER_PLANT] = {
        .mapsec = MAPSEC_POWER_PLANT,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_POWER_PLANT
    },
    //Sevii Islands
    [MPS_MT_EMBER] = {
        .mapsec = MAPSEC_MT_EMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MT_EMBER
    },
    [MPS_ROCKET_WAREHOUSE] = {
        .mapsec = MAPSEC_ROCKET_WAREHOUSE,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_ROCKET_WAREHOUSE
    },
    [MPS_MONEAN_CHAMBER] = {
        .mapsec = MAPSEC_MONEAN_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    },
    [MPS_DOTTED_HOLE] = {
        .mapsec = MAPSEC_DOTTED_HOLE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_DOTTED_HOLE
    },
    [MPS_BERRY_FOREST] = {
        .mapsec = MAPSEC_BERRY_FOREST,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_BERRY_FOREST
    },
    [MPS_ICEFALL_CAVE] = {
        .mapsec = MAPSEC_ICEFALL_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_ICEFALL_CAVE
    },
    [MPS_LOST_CAVE] = {
        .mapsec = MAPSEC_LOST_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_LOST_CAVE
    },
    [MPS_ALTERING_CAVE] = {
        .mapsec = MAPSEC_ALTERING_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_ALTERING_CAVE
    },
    [MPS_PATTERN_BUSH] = {
        .mapsec = MAPSEC_PATTERN_BUSH,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_VIRIDIAN_FOREST
    },
    [MPS_LIPTOO_CHAMBER] = {
        .mapsec = MAPSEC_LIPTOO_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    },
    [MPS_WEEPTH_CHAMBER] = {
        .mapsec = MAPSEC_WEEPTH_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    },
    [MPS_TDILFORD_CHAMBER] = {
        .mapsec = MAPSEC_DILFORD_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    },
    [MPS_SCUFIB_CHAMBER] = {
        .mapsec = MAPSEC_SCUFIB_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    },
    [MPS_RIXY_CHAMBER] = {
        .mapsec = MAPSEC_RIXY_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    },
    [MPS_VIAPOIS_CHAMBER] = {
        .mapsec = MAPSEC_VIAPOIS_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    },
    //Johto
    [MPS_SAFARI_ZONE_JOHTO] = {
        .mapsec = MAPSEC_SAFARI_ZONE,
        .type = MPS_TYPE_BASIC,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_SAFARI_ZONE
    },*/
    //HGSS
    [MPS_HGSS_BURNED_TOWER] = {
        .mapsec = MAPSEC_BURNED_TOWER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_BURNED_TOWER
    },
    [MPS_HGSS_CERULEAN_CAVE] = {
        .mapsec = MAPSEC_CERULEAN_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_CERULEAN_CAVE
    },
    [MPS_HGSS_DARK_CAVE] = {
        .mapsec = MAPSEC_DARK_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_DARK_CAVE
    },
    [MPS_HGSS_DIGGLET_CAVE] = {
        .mapsec = MAPSEC_DIGLETTS_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_DIGGLET_CAVE
    },
    [MPS_HGSS_DRAGON_DEN] = {
        .mapsec = MAPSEC_DRAGONS_DEN,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_DRAGON_DEN
    },
    [MPS_HGSS_ICE_PATH] = {
        .mapsec = MAPSEC_ICE_PATH,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_ICE_PATH
    },
    [MPS_HGSS_ILEX_FOREST] = {
        .mapsec = MAPSEC_ILEX_FOREST,
        .type = MPS_TYPE_BASIC,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_ILEX_FOREST
    },
    [MPS_HGSS_MT_MOON] = {
        .mapsec = MAPSEC_MT_MOON,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_MT_MOON
    },
    [MPS_HGSS_MT_MORTAR] = {
        .mapsec = MAPSEC_MT_MORTAR,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_MT_MORTAR
    },
    [MPS_HGSS_MT_SILVER] = {
        .mapsec = MAPSEC_MT_SILVER_INSIDE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_MT_SILVER
    },
    [MPS_HGSS_NATIONAL_PARK] = {
        .mapsec = MAPSEC_NATIONAL_PARK,
        .type = MPS_TYPE_BASIC,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_NATIONAL_PARK
    },
    [MPS_HGSS_ROCK_TUNNEL] = {
        .mapsec = MAPSEC_ROCK_TUNNEL,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_ROCK_TUNNEL
    },
    [MPS_HGSS_RUINS_OF_ALPH] = {
        .mapsec = MAPSEC_RUINS_OF_ALPH,
        .type = MPS_TYPE_BASIC,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_RUINS_OF_ALPH
    },
    [MPS_HGSS_SEAFOAM_ISLANDS] = {
        .mapsec = MAPSEC_SEAFOAM_ISLANDS,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_SEAFOAM_ISLANDS
    },
    [MPS_HGSS_SLOWPOKE_WELL] = {
        .mapsec = MAPSEC_SLOWPOKE_WELL,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_SLOWPOKE_WELL
    },
    [MPS_HGSS_SPROUT_TOWER] = {
        .mapsec = MAPSEC_SPROUT_TOWER,
        .type = MPS_TYPE_BASIC,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_SPROUT_TOWER
    },
    [MPS_HGSS_TIN_TOWER] = {
        .mapsec = MAPSEC_TIN_TOWER,
        .type = MPS_TYPE_BASIC,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_TIN_TOWER
    },
    [MPS_HGSS_TOHJO_FALLS] = {
        .mapsec = MAPSEC_TOHJO_FALLS,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_TOHJO_FALLS
    },
    [MPS_HGSS_UNION_CAVE] = {
        .mapsec = MAPSEC_UNION_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_UNION_CAVE
    },
    [MPS_HGSS_VICTORY_ROAD] = {
        .mapsec = MAPSEC_VICTORY_ROAD,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_VICTORY_ROAD
    },
    [MPS_HGSS_VIRIDIAN_FOREST] = {
        .mapsec = MAPSEC_VIRIDIAN_FOREST,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_VIRIDIAN_FOREST
    },
    [MPS_HGSS_WHIRL_ISLANDS] = {
        .mapsec = MAPSEC_WHIRL_ISLANDS,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_HGSS_WHIRL_ISLANDS
    }
};

static const struct ImageData sMapPreviewImageData[IMG_COUNT] = {
    /*[IMG_VIRIDIAN_FOREST] = {
        .tilesptr = sViridianForestMapPreviewTiles,
        .tilemapptr = sViridianForestMapPreviewTilemap,
        .palptr = sViridianForestMapPreviewPalette
    },
    [IMG_MT_MOON] = {
        .tilesptr = sMtMoonMapPreviewTiles,
        .tilemapptr = sMtMoonMapPreviewTilemap,
        .palptr = sMtMoonMapPreviewPalette
    },
    [IMG_DIGLETTS_CAVE] = {
        .tilesptr = sDiglettsCaveMapPreviewTiles,
        .tilemapptr = sDiglettsCaveMapPreviewTilemap,
        .palptr = sDiglettsCaveMapPreviewPalette
    },
    [IMG_ROCK_TUNNEL] = {
        .tilesptr = sRockTunnelMapPreviewTiles,
        .tilemapptr = sRockTunnelMapPreviewTilemap,
        .palptr = sRockTunnelMapPreviewPalette
    },
    [IMG_POKEMON_TOWER] = {
        .tilesptr = sPokemonTowerMapPreviewTiles,
        .tilemapptr = sPokemonTowerMapPreviewTilemap,
        .palptr = sPokemonTowerMapPreviewPalette
    },
    [IMG_SAFARI_ZONE] = {
        .tilesptr = sSafariZoneMapPreviewTiles,
        .tilemapptr = sSafariZoneMapPreviewTilemap,
        .palptr = sSafariZoneMapPreviewPalette
    },
    [IMG_SEAFOAM_ISLANDS] = {
        .tilesptr = sSeafoamIslandsMapPreviewTiles,
        .tilemapptr = sSeafoamIslandsMapPreviewTilemap,
        .palptr = sSeafoamIslandsMapPreviewPalette
    },
    [IMG_POKEMON_MANSION] = {
        .tilesptr = sPokemonMansionMapPreviewTiles,
        .tilemapptr = sPokemonMansionMapPreviewTilemap,
        .palptr = sPokemonMansionMapPreviewPalette
    },
    [IMG_ROCKET_HIDEOUT] = {
        .tilesptr = sRocketHideoutMapPreviewTiles,
        .tilemapptr = sRocketHideoutMapPreviewTilemap,
        .palptr = sRocketHideoutMapPreviewPalette
    },
    [IMG_SILPH_CO] = {
        .tilesptr = sSilphCoMapPreviewTiles,
        .tilemapptr = sSilphCoMapPreviewTilemap,
        .palptr = sSilphCoMapPreviewPalette
    },
    [IMG_VICTORY_ROAD] = {
        .tilesptr = sVictoryRoadMapPreviewTiles,
        .tilemapptr = sVictoryRoadMapPreviewTilemap,
        .palptr = sVictoryRoadMapPreviewPalette
    },
    [IMG_CERULEAN_CAVE] = {
        .tilesptr = sCeruleanCaveMapPreviewTiles,
        .tilemapptr = sCeruleanCaveMapPreviewTilemap,
        .palptr = sCeruleanCaveMapPreviewPalette
    },
    [IMG_POWER_PLANT] = {
        .tilesptr = sPowerPlantMapPreviewTiles,
        .tilemapptr = sPowerPlantMapPreviewTilemap,
        .palptr = sPowerPlantMapPreviewPalette
    },
    [IMG_MT_EMBER] = {
        .tilesptr = sMtEmberMapPreviewTiles,
        .tilemapptr = sMtEmberMapPreviewTilemap,
        .palptr = sMtEmberMapPreviewPalette
    },
    [IMG_ROCKET_WAREHOUSE] = {
        .tilesptr = sRocketWarehouseMapPreviewTiles,
        .tilemapptr = sRocketWarehouseMapPreviewTilemap,
        .palptr = sRocketWarehouseMapPreviewPalette
    },
    [IMG_MONEAN_CHAMBER] = {
        .tilesptr = sMoneanChamberMapPreviewTiles,
        .tilemapptr = sMoneanChamberMapPreviewTilemap,
        .palptr = sMoneanChamberMapPreviewPalette
    },
    [IMG_DOTTED_HOLE] = {
        .tilesptr = sDottedHoleMapPreviewTiles,
        .tilemapptr = sDottedHoleMapPreviewTilemap,
        .palptr = sDottedHoleMapPreviewPalette
    },
    [IMG_BERRY_FOREST] = {
        .tilesptr = sBerryForestMapPreviewTiles,
        .tilemapptr = sBerryForestMapPreviewTilemap,
        .palptr = sBerryForestMapPreviewPalette
    },
    [IMG_ICEFALL_CAVE] = {
        .tilesptr = sIcefallCaveMapPreviewTiles,
        .tilemapptr = sIcefallCaveMapPreviewTilemap,
        .palptr = sIcefallCaveMapPreviewPalette
    },
    [IMG_LOST_CAVE] = {
        .tilesptr = sLostCaveMapPreviewTiles,
        .tilemapptr = sLostCaveMapPreviewTilemap,
        .palptr = sLostCaveMapPreviewPalette
    },
    [IMG_ALTERING_CAVE] = {
        .tilesptr = sAlteringCaveMapPreviewTiles,
        .tilemapptr = sAlteringCaveMapPreviewTilemap,
        .palptr = sAlteringCaveMapPreviewPalette
    },*/
    //HGSS
    [IMG_HGSS_BURNED_TOWER] = {
        .tilesptr   = sBurnedTowerMapPreviewTiles,
        .tilemapptr = sBurnedTowerMapPreviewTilemap,
        .palptr     = sBurnedTowerMapPreviewPalette
    },
    [MPS_HGSS_CERULEAN_CAVE] = {
        .tilesptr   = sCeruleanCaveMapPreviewTiles,
        .tilemapptr = sCeruleanCaveMapPreviewTilemap,
        .palptr     = sCeruleanCaveMapPreviewPalette
    },
    [IMG_HGSS_DARK_CAVE] = {
        .tilesptr   = sDarkCaveMapPreviewTiles,
        .tilemapptr = sDarkCaveMapPreviewTilemap,
        .palptr     = sDarkCaveMapPreviewPalette
    },
    [MPS_HGSS_DIGGLET_CAVE] = {
        .tilesptr   = sDiggletCaveMapPreviewTiles,
        .tilemapptr = sDiggletCaveMapPreviewTilemap,
        .palptr     = sDiggletCaveMapPreviewPalette
    },
    [MPS_HGSS_DRAGON_DEN] = {
        .tilesptr   = sDragonsDenMapPreviewTiles,
        .tilemapptr = sDragonsDenMapPreviewTilemap,
        .palptr     = sDragonsDenMapPreviewPalette
    },
    [MPS_HGSS_ICE_PATH] = {
        .tilesptr   = sIcePathMapPreviewTiles,
        .tilemapptr = sIcePathMapPreviewTilemap,
        .palptr     = sIcePathMapPreviewPalette
    },
    [MPS_HGSS_ILEX_FOREST] = {
        .tilesptr   = sIlexForestMapPreviewTiles,
        .tilemapptr = sIlexForestMapPreviewTilemap,
        .palptr     = sIlexForestMapPreviewPalette
    },
    [MPS_HGSS_MT_MOON] = {
        .tilesptr   = sMtMoonMapPreviewTiles,
        .tilemapptr = sMtMoonMapPreviewTilemap,
        .palptr     = sMtMoonMapPreviewPalette
    },
    [MPS_HGSS_MT_MORTAR] = {
        .tilesptr   = sMtMortarMapPreviewTiles,
        .tilemapptr = sMtMortarMapPreviewTilemap,
        .palptr     = sMtMortarMapPreviewPalette
    },
    [MPS_HGSS_MT_SILVER] = {
        .tilesptr   = sMtSilverMapPreviewTiles,
        .tilemapptr = sMtSilverMapPreviewTilemap,
        .palptr     = sMtSilverMapPreviewPalette
    },
    [MPS_HGSS_NATIONAL_PARK] = {
        .tilesptr   = sNationalParkMapPreviewTiles,
        .tilemapptr = sNationalParkMapPreviewTilemap,
        .palptr     = sNationalParkMapPreviewPalette
    },
    [MPS_HGSS_ROCK_TUNNEL] = {
        .tilesptr   = sRockTunnelMapPreviewTiles,
        .tilemapptr = sRockTunnelMapPreviewTilemap,
        .palptr     = sRockTunnelMapPreviewPalette
    },
    [MPS_HGSS_RUINS_OF_ALPH] = {
        .tilesptr   = sRuinsOfAlphMapPreviewTiles,
        .tilemapptr = sRuinsOfAlphMapPreviewTilemap,
        .palptr     = sRuinsOfAlphMapPreviewPalette
    },
    [MPS_HGSS_SEAFOAM_ISLANDS] = {
        .tilesptr   = sSeafoamIslandsMapPreviewTiles,
        .tilemapptr = sSeafoamIslandsMapPreviewTilemap,
        .palptr     = sSeafoamIslandsMapPreviewPalette
    },
    [MPS_HGSS_SLOWPOKE_WELL] = {
        .tilesptr   = sSlowpokeWellMapPreviewTiles,
        .tilemapptr = sSlowpokeWellMapPreviewTilemap,
        .palptr     = sSlowpokeWellMapPreviewPalette
    },
    [MPS_HGSS_SPROUT_TOWER] = {
        .tilesptr   = sSproutTowerMapPreviewTiles,
        .tilemapptr = sSproutTowerMapPreviewTilemap,
        .palptr     = sSproutTowerMapPreviewPalette
    },
    [IMG_HGSS_TIN_TOWER] = {
        .tilesptr   = sTinTowerMapPreviewTiles,
        .tilemapptr = sTinTowerMapPreviewTilemap,
        .palptr     = sTinTowerMapPreviewPalette
    },
    [MPS_HGSS_TOHJO_FALLS] = {
        .tilesptr   = sTohjoFallsMapPreviewTiles,
        .tilemapptr = sTohjoFallsMapPreviewTilemap,
        .palptr     = sTohjoFallsMapPreviewPalette
    },
    [MPS_HGSS_UNION_CAVE] = {
        .tilesptr   = sUnionCaveMapPreviewTiles,
        .tilemapptr = sUnionCaveMapPreviewTilemap,
        .palptr     = sUnionCaveMapPreviewPalette
    },
    [MPS_HGSS_VICTORY_ROAD] = {
        .tilesptr   = sVictoryRoadMapPreviewTiles,
        .tilemapptr = sVictoryRoadMapPreviewTilemap,
        .palptr     = sVictoryRoadMapPreviewPalette
    },
    [MPS_HGSS_VIRIDIAN_FOREST] = {
        .tilesptr   = sViridianForestMapPreviewTiles,
        .tilemapptr = sViridianForestMapPreviewTilemap,
        .palptr     = sViridianForestMapPreviewPalette
    },
    [MPS_HGSS_WHIRL_ISLANDS] = {
        .tilesptr   = sWhirlIslandsMapPreviewTiles,
        .tilemapptr = sWhirlIslandsMapPreviewTilemap,
        .palptr     = sWhirlIslandsMapPreviewPalette
    }
};

static const struct WindowTemplate sMapNameWindow = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 13,
    .height = 2,
    .paletteNum = 14,
    .baseBlock = 0x259
};

static const struct WindowTemplate sMapNameWindowLarge = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 22,
    .height = 2,
    .paletteNum = 14,
    .baseBlock = 0x259
};

static const struct BgTemplate sMapPreviewBgTemplate[1] = {
    {
        .mapBaseIndex = 31
    }
};

static u8 GetMapPreviewScreenIdx(u8 mapsec)
{
    s32 i;

    for (i = 0; i < MPS_COUNT; i++)
    {
        if (sMapPreviewScreenData[i].mapsec == mapsec)
        {
            return i;
        }
    }
    return MPS_COUNT;
}

bool8 MapHasPreviewScreen(u8 mapsec, u8 type)
{
    u8 idx;

    idx = GetMapPreviewScreenIdx(mapsec);
    if (idx != MPS_COUNT)
    {
        if (type == MPS_TYPE_ANY)
        {
            return TRUE;
        }
        else
        {
            return sMapPreviewScreenData[idx].type == type ? TRUE : FALSE;
        }
    }
    else
    {
        return FALSE;
    }
}

bool32 MapHasPreviewScreen_HandleQLState2(u8 mapsec, u8 type)
{
    return MapHasPreviewScreen(mapsec, type);
}

void MapPreview_InitBgs(void)
{
    InitBgsFromTemplates(0, sMapPreviewBgTemplate, NELEMS(sMapPreviewBgTemplate));
    ShowBg(0);
}

void MapPreview_LoadGfx(u8 mapsec)
{
    u8 idx;

    idx = GetMapPreviewScreenIdx(mapsec);
    if (idx != MPS_COUNT)
    {
       ResetTempTileDataBuffers();
        if (MapHasPreviewScreen_HandleQLState2(gMapHeader.regionMapSectionId, MPS_TYPE_FADE_IN) == TRUE)
            LoadPalette(sMapPreviewImageData[sMapPreviewScreenData[idx].image].palptr, BG_PLTT_ID(13), 3 * PLTT_SIZE_4BPP);
        else
            LoadPalette(sMapPreviewImageData[sMapPreviewScreenData[idx].image].palptr, BG_PLTT_ID(0), 16 * PLTT_SIZE_4BPP);
            
       DecompressAndCopyTileDataToVram(0, sMapPreviewImageData[sMapPreviewScreenData[idx].image].tilesptr, 0, 0, 0);
       if (GetBgTilemapBuffer(0) == NULL)
       {
           SetBgTilemapBuffer(0, Alloc(BG_SCREEN_SIZE));
           sAllocedBg0TilemapBuffer = TRUE;
       }
       else
       {
           sAllocedBg0TilemapBuffer = FALSE;
       }
       CopyToBgTilemapBuffer(0, sMapPreviewImageData[sMapPreviewScreenData[idx].image].tilemapptr, 0, 0x000);
       CopyBgTilemapBufferToVram(0);
    }
}

void MapPreview_Unload(s32 windowId)
{
    RemoveWindow(windowId);
    if (sAllocedBg0TilemapBuffer)
    {
        Free(GetBgTilemapBuffer(0));
    }
}

bool32 MapPreview_IsGfxLoadFinished(void)
{
    return FreeTempTileDataBuffersIfPossible();
}

void MapPreview_StartForestTransition(u8 mapsec)
{
    u8 taskId;

    taskId = CreateTask(Task_RunMapPreviewScreenForest, 0);
    gTasks[taskId].data[2] = GetBgAttribute(0, BG_ATTR_PRIORITY);
    gTasks[taskId].data[4] = GetGpuReg(REG_OFFSET_BLDCNT);
    gTasks[taskId].data[5] = GetGpuReg(REG_OFFSET_BLDALPHA);
    gTasks[taskId].data[3] = GetGpuReg(REG_OFFSET_DISPCNT);
    gTasks[taskId].data[6] = GetGpuReg(REG_OFFSET_WININ);
    gTasks[taskId].data[7] = GetGpuReg(REG_OFFSET_WINOUT);
    gTasks[taskId].data[10] = MapPreview_GetDuration(mapsec);
    gTasks[taskId].data[8] = 16;
    gTasks[taskId].data[9] = 0;
    SetBgAttribute(0, BG_ATTR_PRIORITY, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_CLR | WININ_WIN1_CLR);
    SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WIN01_CLR);
    gTasks[taskId].data[11] = MapPreview_CreateMapNameWindow(mapsec);
    LockPlayerFieldControls();
}

u16 MapPreview_CreateMapNameWindow(u8 mapsec)
{
    u16 windowId;
    u32 xctr;
    #ifdef BUGFIX
    // Fixes access violations indicated below.
    u8 color[3];
    #else
    u8 color[0];
    #endif

    //Map names are disabled for HnS, as they are included in the tile image

    /*GetMapName(gStringVar4, mapsec, 0);
    if (GetStringWidth(FONT_NORMAL, gStringVar4, 0) > 104)
    {
        windowId = AddWindow(&sMapNameWindowLarge);
        xctr = 177 - GetStringWidth(FONT_NORMAL, gStringVar4, 0);
    }
    else
    {
        xctr = 104 - GetStringWidth(FONT_NORMAL, gStringVar4, 0);
        windowId = AddWindow(&sMapNameWindow);
    }
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    color[0] = TEXT_COLOR_WHITE; // Access violation
    color[1] = TEXT_COLOR_RED; // Access violation
    color[2] = TEXT_COLOR_LIGHT_GRAY; // Access violation
    AddTextPrinterParameterized4(windowId, FONT_NORMAL, xctr / 2, 2, 0, 0, color, -1, gStringVar4);*/
    return windowId;
}

bool32 ForestMapPreviewScreenIsRunning(void)
{
    if (FuncIsActiveTask(Task_RunMapPreviewScreenForest) == TRUE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void Task_RunMapPreviewScreenForest(u8 taskId)
{
    s16 * data;

    data = gTasks[taskId].data;
    switch (data[0])
    {
    case 0:
        if (!MapPreview_IsGfxLoadFinished() && !IsDma3ManagerBusyWithBgCopy())
        {
            CopyWindowToVram(data[11], COPYWIN_FULL);
            data[0]++;
        }
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            FadeInFromBlack();
            data[0]++;
        }
        break;
    case 2:
        if (IsWeatherNotFadingIn())
        {
            Overworld_PlaySpecialMapMusic();
            data[0]++;
        }
        break;
    case 3:
        data[1]++;
        if (data[1] > data[10] || JOY_HELD(B_BUTTON))
        {
            data[1] = 0;
            data[0]++;
        }
        break;
    case 4:
        switch (data[1])
        {
        case 0:
            data[9]++;
            if (data[9] > 16)
            {
                data[9] = 16;
            }
            break;
        case 1:
            data[8]--;
            if (data[8] < 0)
            {
                data[8] = 0;
            }
            break;
        }
        data[1] = (data[1] + 1) % 3;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(data[8], data[9]));
        if (data[8] == 0 && data[9] == 16)
        {
            FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
            CopyBgTilemapBufferToVram(0);
            data[0]++;
        }
        break;
    case 5:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            MapPreview_Unload(data[11]);
            SetBgAttribute(0, BG_ATTR_PRIORITY, data[2]);
            SetGpuReg(REG_OFFSET_DISPCNT, data[3]);
            SetGpuReg(REG_OFFSET_BLDCNT, data[4]);
            SetGpuReg(REG_OFFSET_BLDALPHA, data[5]);
            SetGpuReg(REG_OFFSET_WININ, data[6]);
            SetGpuReg(REG_OFFSET_WINOUT, data[7]);
            DestroyTask(taskId);
        }
        break;
    }
}

const struct MapPreviewScreen * GetDungeonMapPreviewScreenInfo(u8 mapsec)
{
    u8 idx;

    idx = GetMapPreviewScreenIdx(mapsec);
    if (idx == MPS_COUNT)
    {
        return NULL;
    }
    else
    {
        return &sMapPreviewScreenData[idx];
    }
}

u16 MapPreview_GetDuration(u8 mapsec)
{
    u8 idx;
    u16 flagId;

    idx = GetMapPreviewScreenIdx(mapsec);

    if (idx == MPS_COUNT)
    {
        return 0;
    }

    flagId = sMapPreviewScreenData[idx].flagId;

    if (flagId == MPS_FLAG_NULL) {
        if (MPS_DURATION_ALWAYS != 0) {
            return MPS_DURATION_ALWAYS;
        }
        else
        {
            return MPS_DURATION_NO_FLAG;
        }
    }
    else if (MPS_DURATION_ALWAYS != 0) {
        if (!FlagGet(flagId))
        {
            FlagSet(flagId);
        }
        return MPS_DURATION_ALWAYS;
    }
    else {
        if (!FlagGet(flagId))
        {
            FlagSet(flagId);
            return MPS_DURATION_LONG;
        }
        else
        {
            return MPS_DURATION_SHORT;
        }
    }
}

static void VblankCB_MapPreviewScript(void)
{
    TransferPlttBuffer();
}

#define taskStep        data[0]
#define frameCounter    data[1]
#define MPWindowId      data[2]

void Script_MapPreview(void)
{
    SetVBlankCallback(NULL);
    gMain.savedCallback = CB2_ReturnToFieldContinueScript;
    MapPreview_LoadGfx(gMapHeader.regionMapSectionId);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
    SetVBlankCallback(VblankCB_MapPreviewScript);
    SetMainCallback2(CB2_MapPreviewScript);
    CreateTask(Task_RunMapPreview_Script, 0);
}

static void CB2_MapPreviewScript(void)
{
    RunTasks();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Task_RunMapPreview_Script(u8 taskId)
{
    s16 * data;

    data = gTasks[taskId].data;
    switch (taskStep)
    {
    case 0:
        if (!MapPreview_IsGfxLoadFinished() && !IsDma3ManagerBusyWithBgCopy())
        {
            MPWindowId = MapPreview_CreateMapNameWindow(gMapHeader.regionMapSectionId);
            CopyWindowToVram(MPWindowId, COPYWIN_FULL);
            taskStep++;
        }
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            FadeInFromBlack();
            taskStep++;
        }
        break;
    case 2:
        frameCounter++;
        if (frameCounter > MPS_DURATION_SCRIPT || JOY_HELD(B_BUTTON))
        {
            BeginNormalPaletteFade(PALETTES_ALL, MPS_BASIC_FADE_SPEED, 0, 16, RGB_BLACK);
            frameCounter = 0;
            taskStep++;
        }
        break;
    case 3:
        if (!UpdatePaletteFade())
        {
            MapPreview_Unload(MPWindowId);
            DestroyTask(taskId);
            SetMainCallback2(gMain.savedCallback);
        }
        break;
    }
}

#undef taskStep
#undef frameCounter
#undef MPWindowId