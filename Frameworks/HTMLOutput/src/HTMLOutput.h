#include <oak/misc.h>

extern NSString* const kCommandRunnerURLScheme;

@interface OakHTMLOutputView : NSView
- (void)loadRequest:(NSURLRequest*)aRequest environment:(std::map<std::string, std::string> const&)anEnvironment autoScrolls:(BOOL)flag;
- (void)stopLoadingWithUserInteraction:(BOOL)askUserFlag completionHandler:(void(^)(BOOL didStop))handler;
- (void)loadHTMLString:(NSString*)someHTML;

@property (nonatomic) NSUUID* commandIdentifier; // UUID from initial load request
@property (nonatomic, getter = isRunningCommand, readonly) BOOL runningCommand;

// Read-only access to the webview is given to allow reading page title, etc.
@property (nonatomic, readonly) WebView* webView;
@property (nonatomic, readonly) BOOL needsNewWebView;
@end

namespace command { struct runner_t; typedef std::shared_ptr<runner_t> runner_ptr; }
PUBLIC NSURLRequest* URLRequestForCommandRunner (command::runner_ptr aRunner);
