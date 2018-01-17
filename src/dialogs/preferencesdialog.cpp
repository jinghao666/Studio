/**************************************************************************
This file is part of JahshakaVR, VR Authoring Toolkit
http://www.jahshaka.com
Copyright (c) 2016  GPLv3 Jahshaka LLC <coders@jahshaka.com>

This is free software: you may copy, redistribute
and/or modify it under the terms of the GPLv3 License

For more information see the LICENSE file
*************************************************************************/
#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"
#include <QListWidgetItem>
#include "preferences/worldsettings.h"
#include "../core/settingsmanager.h"
#include "../core/database/database.h"

PreferencesDialog::PreferencesDialog(Database *handle, SettingsManager* settings) :
    QDialog(nullptr),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);

	db = handle;
    this->settings = settings;

    setWindowTitle("Preferences");
    ui->cancelButton->hide();

    connect(ui->okButton, SIGNAL(clicked(bool)), this, SLOT(saveSettings()));

    setupPages();
}

void PreferencesDialog::setupPages()
{
    // can we elimate this to be more permanent? why (was/is) this dynamic really?
    worldSettings = new WorldSettings(db, settings);
    ui->worldLayout->addWidget(worldSettings);
}

void PreferencesDialog::saveSettings()
{
	worldSettings->saveSettings();
	close();
}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}
