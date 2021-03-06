/*
   Copyright 2014 The Trustees of Princeton University

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef _LIBSYNDICATE_MS_FILE_H_
#define _LIBSYNDICATE_MS_FILE_H_

#include "libsyndicate/ms/core.h"

// request to manipulate metadata on the MS
// NOTE: all data here is shallow-copied by request-generating methods--you don't have to free this structure.
struct ms_client_request {
   int op;
   int flags;
   struct md_entry* ent;
   
   // optional; only if performing an ms::ms_update::UPDATE due to a write
   uint64_t* affected_blocks;
   size_t num_affected_blocks;
   
   // optional; only if performing an ms::ms_update::RENAME 
   struct md_entry* dest;
   
   // caller-given context to associate with this requests
   void* cls;
};

// result of a single RPC operation 
struct ms_client_request_result {
   
   int rc;                      // return code from the MS for the operation 
   int reply_error;             // return code from the MS for the request
   uint64_t file_id;            // inode on which we're operating
   struct md_entry* ent;        // will be NULL if there is no entry for this operation 
};


// multi-entry response (e.g. getattr_multi, listdir, etc.) 
struct ms_client_multi_result {
   
   int reply_error;             // result of the multi-RPC 
   int num_processed;           // number of items processed by the MS
   
   struct md_entry* ents;       // entries returned by the MS
   size_t num_ents;             // number of entries returned by the MS
};


typedef map<long, struct md_update> ms_client_update_set;

 
// does an operation return an entry from the MS?
#define MS_CLIENT_OP_RETURNS_ENTRY( op ) ((op) == ms::ms_update::CREATE || (op) == ms::ms_update::UPDATE || (op) == ms::ms_update::CHCOORD || (op) == ms::ms_update::RENAME)

extern "C" {
   
// high-level file metadata API
uint64_t ms_client_make_file_id();
int ms_client_create( struct ms_client* client, uint64_t* file_id, int64_t* write_nonce, struct md_entry* ent );
int ms_client_mkdir( struct ms_client* client, uint64_t* file_id, int64_t* write_nonce, struct md_entry* ent );
int ms_client_delete( struct ms_client* client, struct md_entry* ent );
int ms_client_update_write( struct ms_client* client, int64_t* write_nonce, struct md_entry* ent, uint64_t* affected_blocks, size_t num_affected_blocks );
int ms_client_update( struct ms_client* client, int64_t* write_nonce, struct md_entry* ent );
int ms_client_coordinate( struct ms_client* client, uint64_t* new_coordinator, int64_t* write_nonce, struct md_entry* ent );
int ms_client_rename( struct ms_client* client, int64_t* write_nonce, struct md_entry* src, struct md_entry* dest );

// multi-RPC (i.e. POST) API
int ms_client_run_requests( struct ms_client* client, struct ms_client_request* requests, struct ms_client_request_result* results, size_t num_requests );

// generate requests to be run
int ms_client_create_request( struct ms_client* client, struct md_entry* ent, struct ms_client_request* request );
int ms_client_create_async_request( struct ms_client* client, struct md_entry* ent, struct ms_client_request* request );
int ms_client_mkdir_request( struct ms_client* client, struct md_entry* ent, struct ms_client_request* request );
int ms_client_mkdir_async_request( struct ms_client* client, struct md_entry* ent, struct ms_client_request* request );
int ms_client_update_request( struct ms_client* client, struct md_entry* ent, struct ms_client_request* request );
int ms_client_update_async_request( struct ms_client* client, struct md_entry* ent, struct ms_client_request* request );
int ms_client_update_write_request( struct ms_client* client, struct md_entry* ent, uint64_t* affected_blocks, size_t num_affected_blocks, struct ms_client_request* request );
int ms_client_coordinate_request( struct ms_client* client, struct md_entry* ent );
int ms_client_rename_request( struct ms_client* client, struct md_entry* src, struct md_entry* dest );
int ms_client_delete_request( struct ms_client* client, struct md_entry* ent, struct ms_client_request* request );
int ms_client_delete_async_request( struct ms_client* client, struct md_entry* ent, struct ms_client_request* request );
int ms_client_request_set_cls( struct ms_client_request* request, void* cls );

// results 
int ms_client_download_parse_errors( struct md_download_context* dlctx );
int ms_client_download_interpret_errors( char const* url, int http_status, int curl_rc, int os_err );

// memory management
int ms_client_request_result_free( struct ms_client_request_result* result );
int ms_client_request_result_free_all( struct ms_client_request_result* results, size_t num_results );
int ms_client_multi_result_free( struct ms_client_multi_result* result );

// low-level file API 
int ms_client_populate_update( struct md_update* up, int op, int flags, struct md_entry* ent );

// low-level RPC
int ms_client_single_rpc( struct ms_client* client, int ms_op, int ms_op_flags, struct ms_client_request* request, struct ms_client_request_result* result );
int ms_client_update_rpc( struct ms_client* client, struct md_update* up );

// parsing
int ms_client_parse_reply( struct ms_client* client, ms::ms_reply* src, char const* buf, size_t buf_len, bool verify );
int ms_client_num_expected_reply_ents( size_t num_reqs, int op );

}

#endif