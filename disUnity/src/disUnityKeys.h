#pragma once

#ifdef DISUNITY_GLFW_WINDOW
	#define DISUNITY_KEY_SPACE              32
	#define DISUNITY_KEY_APOSTROPHE         39  /* ' */
	#define DISUNITY_KEY_COMMA              44  /* , */
	#define DISUNITY_KEY_MINUS              45  /* - */
	#define DISUNITY_KEY_PERIOD             46  /* . */
	#define DISUNITY_KEY_SLASH              47  /* / */
	#define DISUNITY_KEY_0                  48
	#define DISUNITY_KEY_1                  49
	#define DISUNITY_KEY_2                  50
	#define DISUNITY_KEY_3                  51
	#define DISUNITY_KEY_4                  52
	#define DISUNITY_KEY_5                  53
	#define DISUNITY_KEY_6                  54
	#define DISUNITY_KEY_7                  55
	#define DISUNITY_KEY_8                  56
	#define DISUNITY_KEY_9                  57
	#define DISUNITY_KEY_SEMICOLON          59  /* ; */
	#define DISUNITY_KEY_EQUAL              61  /* = */
	#define DISUNITY_KEY_A                  65
	#define DISUNITY_KEY_B                  66
	#define DISUNITY_KEY_C                  67
	#define DISUNITY_KEY_D                  68
	#define DISUNITY_KEY_E                  69
	#define DISUNITY_KEY_F                  70
	#define DISUNITY_KEY_G                  71
	#define DISUNITY_KEY_H                  72
	#define DISUNITY_KEY_I                  73
	#define DISUNITY_KEY_J                  74
	#define DISUNITY_KEY_K                  75
	#define DISUNITY_KEY_L                  76
	#define DISUNITY_KEY_M                  77
	#define DISUNITY_KEY_N                  78
	#define DISUNITY_KEY_O                  79
	#define DISUNITY_KEY_P                  80
	#define DISUNITY_KEY_Q                  81
	#define DISUNITY_KEY_R                  82
	#define DISUNITY_KEY_S                  83
	#define DISUNITY_KEY_T                  84
	#define DISUNITY_KEY_U                  85
	#define DISUNITY_KEY_V                  86
	#define DISUNITY_KEY_W                  87
	#define DISUNITY_KEY_X                  88
	#define DISUNITY_KEY_Y                  89
	#define DISUNITY_KEY_Z                  90
	#define DISUNITY_KEY_LEFT_BRACKET       91  /* [ */
	#define DISUNITY_KEY_BACKSLASH          92  /* \ */
	#define DISUNITY_KEY_RIGHT_BRACKET      93  /* ] */
	#define DISUNITY_KEY_GRAVE_ACCENT       96  /* ` */
	#define DISUNITY_KEY_WORLD_1            161 /* non-US #1 */
	#define DISUNITY_KEY_WORLD_2            162 /* non-US #2 */

	/* Function keys */
	#define DISUNITY_KEY_ESCAPE             256
	#define DISUNITY_KEY_ENTER              257
	#define DISUNITY_KEY_TAB                258
	#define DISUNITY_KEY_BACKSPACE          259
	#define DISUNITY_KEY_INSERT             260
	#define DISUNITY_KEY_DELETE             261
	#define DISUNITY_KEY_RIGHT              262
	#define DISUNITY_KEY_LEFT               263
	#define DISUNITY_KEY_DOWN               264
	#define DISUNITY_KEY_UP                 265
	#define DISUNITY_KEY_PAGE_UP            266
	#define DISUNITY_KEY_PAGE_DOWN          267
	#define DISUNITY_KEY_HOME               268
	#define DISUNITY_KEY_END                269
	#define DISUNITY_KEY_CAPS_LOCK          280
	#define DISUNITY_KEY_SCROLL_LOCK        281
	#define DISUNITY_KEY_NUM_LOCK           282
	#define DISUNITY_KEY_PRINT_SCREEN       283
	#define DISUNITY_KEY_PAUSE              284
	#define DISUNITY_KEY_F1                 290
	#define DISUNITY_KEY_F2                 291
	#define DISUNITY_KEY_F3                 292
	#define DISUNITY_KEY_F4                 293
	#define DISUNITY_KEY_F5                 294
	#define DISUNITY_KEY_F6                 295
	#define DISUNITY_KEY_F7                 296
	#define DISUNITY_KEY_F8                 297
	#define DISUNITY_KEY_F9                 298
	#define DISUNITY_KEY_F10                299
	#define DISUNITY_KEY_F11                300
	#define DISUNITY_KEY_F12                301
	#define DISUNITY_KEY_F13                302
	#define DISUNITY_KEY_F14                303
	#define DISUNITY_KEY_F15                304
	#define DISUNITY_KEY_F16                305
	#define DISUNITY_KEY_F17                306
	#define DISUNITY_KEY_F18                307
	#define DISUNITY_KEY_F19                308
	#define DISUNITY_KEY_F20                309
	#define DISUNITY_KEY_F21                310
	#define DISUNITY_KEY_F22                311
	#define DISUNITY_KEY_F23                312
	#define DISUNITY_KEY_F24                313
	#define DISUNITY_KEY_F25                314
	#define DISUNITY_KEY_KP_0               320
	#define DISUNITY_KEY_KP_1               321
	#define DISUNITY_KEY_KP_2               322
	#define DISUNITY_KEY_KP_3               323
	#define DISUNITY_KEY_KP_4               324
	#define DISUNITY_KEY_KP_5               325
	#define DISUNITY_KEY_KP_6               326
	#define DISUNITY_KEY_KP_7               327
	#define DISUNITY_KEY_KP_8               328
	#define DISUNITY_KEY_KP_9               329
	#define DISUNITY_KEY_KP_DECIMAL         330
	#define DISUNITY_KEY_KP_DIVIDE          331
	#define DISUNITY_KEY_KP_MULTIPLY        332
	#define DISUNITY_KEY_KP_SUBTRACT        333
	#define DISUNITY_KEY_KP_ADD             334
	#define DISUNITY_KEY_KP_ENTER           335
	#define DISUNITY_KEY_KP_EQUAL           336
	#define DISUNITY_KEY_LEFT_SHIFT         340
	#define DISUNITY_KEY_LEFT_CONTROL       341
	#define DISUNITY_KEY_LEFT_ALT           342
	#define DISUNITY_KEY_LEFT_SUPER         343
	#define DISUNITY_KEY_RIGHT_SHIFT        344
	#define DISUNITY_KEY_RIGHT_CONTROL      345
	#define DISUNITY_KEY_RIGHT_ALT          346
	#define DISUNITY_KEY_RIGHT_SUPER        347
	#define DISUNITY_KEY_MENU               348
#else
	#definition_DISUNITY_GLFW_is_missing
#endif
