//
//  CUPreferences.h
//  Khronos
//
//  Created by Gautam Dey on 7/5/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
extern NSString *const CUPreferencesResetNotification;
extern NSString *const CUPreferencesAskDeleteJob;
extern NSString *const CUPreferencesAskDeleteSession;
extern NSString *const CUPreferencesAutoSaveTime;
extern NSString *const CUPreferencesAutoDeleteSettings;
extern NSString *const CUPreferencesClockSetting;
extern NSString *const CUPreferencesUpdateTime;
extern NSString *const CUPreferencesMonetaryUnit;
extern NSString *const CUPreferencesFirstLaunch;
extern NSString *const CUPreferencesTimeSettingsChangedNotification;
extern NSString *const CUPreferencesClockSettingNotification;
extern NSString *const CUPreferencesUpdateTimeNotification;

extern NSString *const CUPreferencesTableNotification;      
extern NSString *const CUPreferencesTableUserInfoTableName; 
extern NSString *const CUPreferencesTableUserInfoColumnName;

/*** Which columns in the Project table should be shown. ***/
extern NSString *const CUPreferencesProjectDisplay;
extern NSString *const CUPreferencesProjectDisplayNumber;
extern NSString *const CUPreferencesProjectDisplayName;
extern NSString *const CUPreferencesProjectDisplayClient;
extern NSString *const CUPreferencesProjectDisplayRate;
extern NSString *const CUPreferencesProjectDisplayTime;
extern NSString *const CUPreferencesProjectDisplayCharges;

/*** Which columns in the Seesion Table should be shown. ***/
extern NSString *const CUPreferencesSessionDisplay;
extern NSString *const CUPreferencesSessionDisplayStartDate;
extern NSString *const CUPreferencesSessionDisplayEndDate;
extern NSString *const CUPreferencesSessionDisplayStartTime;
extern NSString *const CUPreferencesSessionDisplayEndTime;
extern NSString *const CUPreferencesSessionDisplayPauseTime;
extern NSString *const CUPreferencesSessionDisplayTotalTime;
extern NSString *const CUPreferencesSessionDisplayCharges;
extern NSString *const CUPreferencesSessionDisplaySummary;
extern NSString *const CUPreferencesSessionDisplayNumber;

/*** Options for the menu bar ***/
extern NSString *const CUPreferencesMenuDisplay;
extern NSString *const CUPreferencesMenuDisplayPauseButton;
extern NSString *const CUPreferencesMenuDisplayRecrodingButton;
extern NSString *const CUPreferencesMenuDisplayProjectList;
extern NSString *const CUPreferencesMenuDisplayTotalTime;
extern NSString *const CUPreferencesMenuDisplayCharges;

/*** Options for Invoice ***/
extern NSString *const CUPreferencesInvoice;
extern NSString *const CUPreferencesInvoiceIndexTitle;
extern NSString *const CUPreferencesInvoiceIndexHeading;
extern NSString *const CUPreferencesInvoiceLinkHelp;
extern NSString *const CUPreferencesInvoiceTitle;
extern NSString *const CUPreferencesInvoiceHeading;
extern NSString *const CUPreferencesInvoiceBodyFont;
extern NSString *const CUPreferencesInvoiceHeadingFont;


extern NSString *const CUPreferencesInvoiceIndexTitleChangedNotification;  
extern NSString *const CUPreferencesInvoiceIndexHeadingChangedNotification;
extern NSString *const CUPreferencesInvoiceLinkHelpChangedNotification;    
extern NSString *const CUPreferencesInvoiceTitleChangedNotification;       
extern NSString *const CUPreferencesInvoiceHeadingChangedNotification;
extern NSString *const CUPreferencesInvoiceHeadingFontChangedNotification;
extern NSString *const CUPreferencesInvoiceBodyFontChangedNotification;    

@interface CUPreferences : NSObject {

}

+ (void) resetPreferences;
+ (void) initializeDefaults;

// Functions for working with the various tables.
// These functions will work for the Project Table, Session Table and te Menu. 
// Basically any of the Contstand with the word Display at the end of it.
- (NSDictionary *)columnsForTable:(NSString *)tableName;
- (void) setTable:(NSString *)tableName column:(NSString *)column display:(BOOL)yn;
- (BOOL) displayForTable:(NSString *)tableName column:(NSString *)column;

#pragma mark General Options
- (BOOL) askDeleteProject;
- (void) setAskDeleteProject:(BOOL)value;
- (BOOL) askDeleteSession;
- (void) setAskDeleteSession:(BOOL)value;
// Should this return an int?
- (BOOL) autoSaveTime;
- (void) setAutoSaveTime:(BOOL)value;
- (BOOL) autoDeleteSettings;
- (void) setAutoDeleteSettings:(BOOL)value;
- (BOOL) is24HourClock;
- (void) setIs24HourClock:(BOOL)value;
- (int) updateTimeEvery;
- (void) setUpdateTimeEvery:(int)minutes;
- (NSString *)monetaryUnit;
- (void) setMonetaryUnit:(NSString *)unit;
- (BOOL) firstLaunch;


#pragma mark Invoice Options
- (NSDictionary *)invoiceTable;
- (id)invoiceValuesForColumn:(NSString *)column;
- (void)setInvoiceValueForColumn:(NSString *)column value:(id)value;
- (NSString *)invoiceIndexTitle;
- (void) setInvoiceIndexTitle:(NSString *)title;
- (NSString *)invoiceIndexHeading;
- (void) setInvoiceIndexHeading:(NSString *)heading;
- (NSString *)invoiceLinkHelp;
- (void) setInvoiceLinkHelp:(NSString *)linkHelp;
- (NSString *)invoiceTitle;
- (void) setInvoiceTitle:(NSString  *)title;
- (NSString *)invoiceHeading;
- (void)setInvoiceHeading:(NSString *)heading;
- (NSFont *)invoiceHeadingFont;
- (void)setInvoiceHeadingFont:(NSFont *)aFont;
- (NSFont *)invoiceBodyFont;
- (void)setInvoiceBodyFont:(NSFont *)aFont;

@end
