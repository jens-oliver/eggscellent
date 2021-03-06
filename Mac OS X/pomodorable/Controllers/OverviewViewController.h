//
//  OverviewViewController.h
//  pomodorable
//
//  Created by Kyle Kinkade on 11/6/11.
//  Copyright (c) 2011 Monocle Society LLC All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PanelController.h"
#import "AboutWindowController.h"
#import "RegistrationWindowController.h"

@interface OverviewViewController : NSViewController
{
    IBOutlet NSTableView            *itemsTableView;
    IBOutlet NSMenu                 *optionsMenu;
    IBOutlet NSMenuItem             *listsSubMenu;
    IBOutlet NSMenuItem             *selectedListMenuItem;
    IBOutlet NSArrayController      *arrayController;
    IBOutlet NSButton               *startButton;
    IBOutlet NSButton               *addTaskButton;
    IBOutlet NSSearchField          *searchField;
    IBOutlet NSScrollView           *listScrollView;
    IBOutlet NSTextField            *noTaskLabel;
    IBOutlet NSButton               *trialButton;

    int                              currentClippedRow;
    int                              previousSelectedRow;
    BOOL                             doubleClicked;
    BOOL                             firstRun;
    
    NSMutableAttributedString       *startString;
    NSMutableAttributedString       *stopString;
    NSMutableAttributedString       *resumeString;

    NSManagedObjectContext          *__weak _managedObjectContext;
    AboutWindowController           *_aboutWindowController;
}
@property (weak, nonatomic, readonly) NSArray                       *activitySortDescriptors;
@property (weak, nonatomic, readonly) NSManagedObjectContext        *managedObjectContext;
@property (nonatomic, strong)   PanelController                     *panelController;
@property (nonatomic, strong)   AboutWindowController               *aboutWindowController;
@property (nonatomic, strong)   RegistrationWindowController        *registrationWindowController;

- (void)viewWillAppear;
- (void)viewDidAppear;
- (void)viewDidDisappear;

- (IBAction)addItem:(id)sender;
- (IBAction)startANewPomodoro:(id)sender;
- (IBAction)pinPanel:(id)sender;
- (IBAction)showOptionsMenu:(id)sender;
- (IBAction)cellDoubleClicked:(id)sender;
- (IBAction)checkForUpdates:(id)sender;

- (IBAction)registrationSelected:(id)sender;

- (IBAction)statsSelected:(id)sender;

- (IBAction)openPreferences:(id)sender;
- (IBAction)showAboutMenu:(id)sender;
- (IBAction)showHelpMenu:(id)sender;

- (IBAction)quitApplication:(id)sender;
- (IBAction)closePanelWindow:(id)sender;

- (IBAction)debugSelected:(id)sender;

- (IBAction)increasePomodoroCountForSelectedRow:(id)sender;
- (IBAction)decreasePomodoroCountForSelectedRow:(id)sender;

- (void)changeButtonToStart:(BOOL)start;
- (void)modifyPomodoroCountForSelectedRow:(int)modValue;
@end
