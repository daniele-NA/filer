
#pragma once

#define LLM_RESPONSE char*

#include <curl/curl.h>

LLM_RESPONSE get_welcome_message();

size_t write_callback(void * contents,size_t size,size_t nmemb,void * user_pt);

void set_headers(CURL *curl,const char *api_key);

void set_data(CURL *curl,char * prompt);