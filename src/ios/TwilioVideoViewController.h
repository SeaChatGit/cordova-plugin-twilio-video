@import TwilioVideo;
@import UIKit;
#import "TwilioVideoManager.h"
#import "TwilioVideoConfig.h"
#import "TwilioVideoPermissions.h"
#import "TwilioVideoUtils.h"

@interface TwilioVideoViewController: UIViewController <TVIRemoteParticipantDelegate, TVIRoomDelegate, TVIVideoViewDelegate, TVICameraSourceDelegate, TwilioVideoActionProducerDelegate, TVILocalParticipantDelegate>

// Configure access token manually for testing in `ViewDidLoad`, if desired! Create one manually in the console.
@property (nonatomic, strong) NSString *roomName;
@property (nonatomic, strong) NSString *accessToken;
@property (nonatomic, strong) TwilioVideoConfig *config;

#pragma mark Video SDK components

@property (nonatomic, strong) TVICameraSource *camera;

@property (nonatomic, strong) TVILocalVideoTrack *localVideoTrack;
@property (nonatomic, strong) TVILocalAudioTrack *localAudioTrack;

@property (nonatomic, strong) TVIRemoteParticipant *remoteParticipant;
@property (nonatomic, weak) TVIVideoView *remoteVideoView;

@property (nonatomic, strong) TVIRoom *room;

#pragma mark UI Element Outlets and handles

// `TVIVideoView` created from a storyboard
@property (weak, nonatomic) IBOutlet TVIVideoView *previewView;
@property (unsafe_unretained, nonatomic) IBOutlet UIView *viewBorderFor_previewView;
@property (unsafe_unretained, nonatomic) IBOutlet UIView *viewLocalCameraDisabled;

@property (nonatomic, weak) IBOutlet UIButton *disconnectButton;
@property (nonatomic, weak) IBOutlet UIButton *micButton;
@property (nonatomic, weak) IBOutlet UIButton *switchAudioButton;
@property (nonatomic, weak) IBOutlet UILabel *roomLabel;
@property (nonatomic, weak) IBOutlet UILabel *roomLine;

@property (nonatomic, weak) IBOutlet UIButton *videoButton;
@property (nonatomic, weak) IBOutlet UIButton *buttonDebugStartACall;


//------------------------------------------------------------------------------
//LOCAL - part 1
- (void)openRoom:(NSString*)room token:(NSString *)token
                         localUserName:(NSString *)localUserName
                     localUserPhotoURL:(NSString *)localUserPhotoURL
                        remoteUserName:(NSString *)remoteUserName
                    remoteUserPhotoURL:(NSString *)remoteUserName;

//LOCAL - part 2
- (void)startCall:(NSString*)room token: (NSString *)token;

//---------------------------------------------------------
//REMOTE - Part 1/1
- (void)answerCall:(NSString*)room token:(NSString *)token
     localUserName:(NSString *)localUserName
 localUserPhotoURL:(NSString *)localUserPhotoURL
    remoteUserName:(NSString *)localUserName
remoteUserPhotoURL:(NSString *)localUserPhotoURL;

//------------------------------------------------------------------------------
//internet gone - seachat tells plugin to show alert
- (void)showOffline;

//internet returned - seachat tells plugin to hide alert
- (void)showOnline;

//------------------------------------------------------------------------------
//BACK TO CALL button just hides the TVC.view / cordova show_twiliovideocontroller() shows it again
-(void) show_twiliovideo;
-(void) hide_twiliovideo;

@end
