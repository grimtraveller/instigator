#define JUCE_ONLY_BUILD_CORE_LIBRARY	0

/* components */
#define JUCE_WEB_BROWSER				0
#define JUCE_USE_CAMERA					0
#define JUCE_ALSA						0
#define JUCE_JACK						0
#define JUCE_QUICKTIME					0
#define JUCE_SUPPORT_CARBON				1
#define JUCE_OPENGL						0
#define JUCE_USE_FLAC					0
#define JUCE_USE_OGGVORBIS				0
#define JUCE_USE_CDBURNER				0
#define JUCE_USE_XINERAMA				0
#define JUCE_USE_XSHM					0
#define JUCE_PLUGINHOST_VST				1
#define JUCE_PLUGINHOST_AU				1

/* debugging */
#ifdef JUCE_DEBUG
#define JUCE_CHECK_MEMORY_LEAKS			1
#else
#define JUCE_CHECK_MEMORY_LEAKS			0
#endif

#define JUCE_CATCH_UNHANDLED_EXCEPTIONS	0
#define JUCE_STRINGS_ARE_UNICODE		1
#define JUCE_ENABLE_REPAINT_DEBUGGING	0

#ifdef JUCE_DEBUG
#define JUCE_FORCE_DEBUG				1
#else
#define JUCE_FORCE_DEBUG				0
#endif

#define JUCE_LOG_ASSERTIONS				0
/* sound */
#define JUCE_ASIO						1
#define JUCE_WASAPI						1
#define JUCE_DIRECTSOUND				1
