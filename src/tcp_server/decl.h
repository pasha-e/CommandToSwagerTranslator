#ifndef tcp_server_decl_h
#define tcp_server_decl_h

#if defined(_WIN32) && (defined( SKIFADAPTERS_MNITI_TCP_SERVER_DYN_LINK ) || defined( MNITI_MNITI_ALL_DYN_LINK ))
#  if defined( SKIFADAPTERS_MNITI_TCP_SERVER_SOURCE )
#    define SKIFADAPTERS_MNITI_TCP_SERVER_DECL __declspec( dllexport )
#  else
#    define SKIFADAPTERS_MNITI_TCP_SERVER_DECL __declspec( dllimport )
#  endif
#else
#  define SKIFADAPTERS_MNITI_TCP_SERVER_DECL
#endif

#endif
