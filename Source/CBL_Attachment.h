//
//  CBL_Attachment.h
//  CouchbaseLite
//
//  Created by Jens Alfke on 4/3/12.
//  Copyright (c) 2012-2013 Couchbase, Inc. All rights reserved.
//

#import "CBLDatabase+Attachments.h"
#import "CBL_BlobStore.h"


/** A simple container for attachment metadata. */
@interface CBL_Attachment : NSObject
{
    @private
    NSString* _name;
    NSString* _contentType;
    
    @public
    // Yes, these are public. They're simple scalar values so it's not really worth
    // creating accessor methods for them all.
    CBLBlobKey blobKey;
    UInt64 length;
    UInt64 encodedLength;
    CBLAttachmentEncoding encoding;
    unsigned revpos;
}

- (instancetype) initWithName: (NSString*)name contentType: (NSString*)contentType;

@property (readonly) bool isValid;

@property (readonly, nonatomic) NSString* name;
@property (readonly, nonatomic) NSString* contentType;

@property CBL_BlobStore* blobStore;

@property (readonly) NSData* content;
@property (readonly) NSData* encodedContent;
@property (readonly) NSInputStream* contentStream;
@property (readonly) NSString* contentFilePath;  // nil if the content is encrypted on disk

@end
