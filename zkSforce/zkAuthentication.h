// Copyright (c) 2011 Simon Fell
//
// Permission is hereby granted, free of charge, to any person obtaining a 
// copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included 
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
// THE SOFTWARE.
//

#import "zkBaseClient.h"

@class ZKLoginResult;

@protocol ZKAuthenticationInfo 

-(NSString *)sessionId;
-(NSURL *)instanceUrl;
-(void)refresh;             // force the sessionId to be refreshed.
-(void)refreshIfNeeded;

@end

@interface ZKOAuthInfo : NSObject <ZKAuthenticationInfo> {
    NSString *sessionId, *refreshToken;
    NSURL *instanceUrl, *authUrl;
}

+(id)oauthInfoWithRefreshToken:(NSString *)tkn authUrl:(NSURL *)auth;
+(id)oauthInfoWithRefreshToken:(NSString *)tkn authUrl:(NSURL *)auth sessionId:(NSString *)sid instanceUrl:(NSURL *)inst;

-(id)initWithRefreshToken:(NSString *)tkn authUrl:(NSURL *)authUrl sessionId:(NSString *)sid instanceUrl:(NSURL *)inst;

@end

@interface ZKSoapLogin : ZKBaseClient<ZKAuthenticationInfo> {
    NSString *username, *password, *sessionId, *clientId;
    NSURL *instanceUrl, *authUrl;
    NSDate		*sessionExpiresAt;
}

+(id)soapLoginWithUsername:(NSString *)un password:(NSString *)pwd authHost:(NSURL *)auth apiVersion:(int)v clientId:(NSString *)cid;

-(ZKLoginResult *)login;
@end