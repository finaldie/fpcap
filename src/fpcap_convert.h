#ifndef FPCAP_CONVERT_H
#define FPCAP_CONVERT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <time.h>

typedef enum {
    FPCAP_SUCCESS = 0,
    FPCAP_OP_OFFLINE_FAILED,
    FPCAP_COMPILE_ERROR,
    FPCAP_SET_FILTER_ERROR,
    FPCAP_LOOP_ERROR
} fpcap_status;

typedef enum {
    FPCAP_CONV_CLIENT = 0x1,
    FPCAP_CONV_SERVER = 0x2
} FPCAP_CONV_TYPE;

#pragma pack(4)
typedef struct {
    struct timeval ts;
    char*  data;
    int    len;
    uint32_t ack;
    uint32_t seq;
} fapp_data_t;
#pragma pack()

typedef struct session_t {
    uint64_t id;
    void*    ud; // this ud for better to save some data, but user take the free responsibility
} session_t;

typedef enum {
    FSESSION_CREATE,
    FSESSION_DELETE,
    FSESSION_PROCESS
} fsession_event;

typedef void (*fconv_handler)(fsession_event, session_t*, fapp_data_t*, void* ud);
typedef void (*fsession_end)(session_t*, void* ud);

#pragma pack(4)
typedef struct convert_action_t {
    const char*   pcap_filename;
    const char*   filter_rules;
    fconv_handler handler;
    fsession_end  cleanup;
    void*         ud;
    uint32_t      type; //convertion type:CLIENT, SERVER, CLIENT|SERVER
} convert_action_t;
#pragma pack()

fpcap_status fpcap_convert(convert_action_t);

#ifdef __cplusplus
}
#endif

#endif
