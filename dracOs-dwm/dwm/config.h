/* See LICENSE file for copyright and license details. */

/**
 * dracOs DWM (Dynamic Window Manager) configuration
 * custom DWM for dracOs
 *
 * Xathrya    (2017) <xathrya@dracos-linux.org>
 * Randalltux (2016) <rndtx@dracos-linux.org>
 */

/* appearance */
static const char colors[SchemeLast][3][8] = {
//     border    foreground   background
   { "#C5C8C6", "#C5C8C6", "#000000" },  // 1 = normal empty
   { "#515151", "#6e6e6e", "#000000" },  // 2 = selected
   { "#000000", "#C5C8C6", "#000000" },  // 3 = Occupied tag
   { "#000000", "#7a7a7a", "#C5C8C6" },  // 4 = Layoutbar
   { "#000000", "#6e6e6e", "#000000" },  // 5 = Titlebar
   { "#000000", "#C5C8C6", "#C5C8C6" },  // 6 = Status Text
   { "#000000", "#C5C8C6", "#C5C8C6" },  // 7 = Status Icon
};

#define CLR_NORMAL       0
#define CLR_SELECT       1
#define CLR_OCCUPIED     2
#define CLR_LAYOUTBAR    3
#define CLR_TITLEBAR     4
#define CLR_STATTEXT     5
#define CLR_STATICON     5

#define SCH_BORDER       0
#define SCH_FG           1
#define SCH_BG           2

static const char *fonts[] = {
	"drift:size=10"
};
static const unsigned int borderpx  = 1; 		// Window Border width
static const unsigned int snap      = 11; 		// Window Snap
static const unsigned int barpadding= 11;		// Bar vertical Padding
static const unsigned int gappx		= 1;		// gap pixel between windows
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int secondbar          = 1;        /* 0 means no extra bar */
static const unsigned int marginbottom 	= 0;

/* tagging */
static const char *tags[] = { "  MAIN  ", "  DEVEL  ", "  PENTEST  ","  MISC  "};
wm-dracos/dwm/
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	 /* class      instance    title     tags mask    iscentered     isfloating   monitor */
	 { "Gcolor2",  NULL,       NULL,     0,           0,             1,        -1 },
	 { "feh",      NULL,       NULL,     0,           0,             1,        -1 },
	 { "XClock",   NULL,       NULL,     0,           0,             1,        -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

// Layout Icons
static const Layout layouts[] = {
//	   Symbol      Layout
	{ " ù ",       NULL           },    // ><>
	{ " ø ",       tile           },    // []=
	{ " ú ",       monocle        },    // [M]
	{ " ð ",       gaplessgrid    },
	{ " ã ",       bstack         },    // TTT
	{ " ü ",       deck           },
	{ " Î ",       col            },    // |||
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]	= { "urxvt", "-name", "Console", NULL };
static const char *filecmd[]	= { "urxvt", "-name", "FileManager", "-e", "ranger", NULL };
static const char *webcmd[]     = { "links", "-g", NULL };
static const char *w3m[]	    = { "w3m", NULL };
static const char *dracosmenu[]	= { "dmenu", "~/.script/dracosmenu", NULL };
static const char *scrotcmd[]	= { "scrot", NULL };

static Key keys[] = {
	/* modifier             key         function            argument */
	{                0,     XK_Print,   spawn,		        {.v = scrotcmd } },
	{ MODKEY|ShiftMask,     XK_Return,  spawn,              {.v = termcmd } },
	{ MODKEY|ShiftMask,     XK_d,	    spawn,              {.v = dracosmenu } },
	{ MODKEY|ShiftMask,     XK_t,	    spawn,              {.v = filecmd } },
	{ MODKEY|ShiftMask,     XK_l,	    spawn,              {.v = webcmd } },
	{ MODKEY|ShiftMask, 	XK_w,	    spawn,              {.v = w3m } },
	{ MODKEY,               XK_f,       setlayout,          {.v = &layouts[0]} },
	{ MODKEY,               XK_t,       setlayout,          {.v = &layouts[1]} },
	{ MODKEY,               XK_m,       setlayout,          {.v = &layouts[2]} },
	{ MODKEY,               XK_g,	    setlayout,	        {.v = &layouts[3]} },
	{ MODKEY,               XK_s,       setlayout,          {.v = &layouts[4]} },
	{ MODKEY,               XK_o,       setlayout,          {.v = &layouts[5]} },
	{ MODKEY,               XK_c,       setlayout,          {.v = &layouts[6]} },
	{ MODKEY,               XK_equal,   incnmaster,         {.i = -1 } },
	{ MODKEY,               XK_minus,   incnmaster,         {.i = +1 } },
	{ MODKEY,               XK_Return,  zoom,               {0} },
	{ MODKEY,               XK_h,       setmfact,           {.f = -0.02} },
	{ MODKEY,               XK_l,       setmfact,           {.f = +0.02} },
	{ MODKEY,               XK_space,   togglefloating,     {0} },
	{ MODKEY,               XK_b,       togglebar,          {0} },
	{ MODKEY,               XK_b,       togglesecondbar,    {0} },
	{ MODKEY,               XK_Tab,     focusstack,         {.i = +1 } },
	{ MODKEY|ShiftMask, 	XK_c, 	    killclient,         {0} },
	{ MODKEY,               XK_Left,    cycle, 		        {.i = -1} },
	{ MODKEY,               XK_Right,   cycle, 		        {.i = +1} },
	{ MODKEY|ShiftMask,     XK_Left,    tagcycle, 	        {.i = -1} },
	{ MODKEY|ShiftMask,     XK_Right,   tagcycle, 	        {.i = +1} },
	TAGKEYS(                XK_1,                            0)
	TAGKEYS(                XK_2,                            1)
	TAGKEYS(                XK_3,                            2)
	TAGKEYS(                XK_4,                            3)
	{ MODKEY|ShiftMask,     XK_r,       restart,            {0} },
	{ MODKEY|ShiftMask,     XK_q,       quit,           	{1} },

    /* Move */
    { MODKEY,                       XK_Down,        moveresize,         {.v = "0x 25y 0w 0h"}},
    { MODKEY,                       XK_Up,          moveresize,         {.v = "0x -25y 0w 0h"}},
    { MODKEY,                       XK_Right,       moveresize,         {.v = "25x 0y 0w 0h"}},
    { MODKEY,                       XK_Left,        moveresize,         {.v = "-25x 0y 0w 0h"}},

    /* resize */
    { MODKEY|ShiftMask,             XK_Down,        moveresize,         {.v = "0x 0y 0w 25h"}},
    { MODKEY|ShiftMask,             XK_Up,          moveresize,         {.v = "0x 0y 0w -25h"}},
    { MODKEY|ShiftMask,             XK_Right,       moveresize,         {.v = "0x 0y 25w 0h"}},
    { MODKEY|ShiftMask,             XK_Left,        moveresize,         {.v = "0x 0y -25w 0h"}},

};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

