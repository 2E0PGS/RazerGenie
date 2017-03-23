/*
 * Copyright (C) 2016-2017  Luca Weiss <luca (at) z3ntu (dot) xyz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef KCM_RAZERDRIVERS_H
#define KCM_RAZERDRIVERS_H

#include "ui_kcm_razerdrivers.h"
#include "ui_daemon_not_available.h"
#include "razerimagedownloader.h"
#include "librazer/librazer.h"
#include <QComboBox>

class kcm_razerdrivers : public QWidget
{
    Q_OBJECT
public:
    kcm_razerdrivers(QWidget* parent = 0);
    ~kcm_razerdrivers();
public slots:
    void toggleSync(bool);
    void toggleOffOnScreesaver(bool on);
    void imageDownloaded(QString &serial, QString &filename);

    void colorButtonClicked();

    void standardCombo(int index);
    void scrollCombo(int index);
    void logoCombo(int index);

    void brightnessChanged(int value);
    void scrollBrightnessChanged(int value);
    void logoBrightnessChanged(int value);

    void dpiChanged(int value);
    void dpiSyncCheckbox(bool checked);

    void activeCheckbox(bool checked);

    void applyEffect(librazer::Device::lightingLocation loc);
    void applyEffectStandardLoc(bool checked);
    void applyEffectLogoLoc(bool checked);
    void applyEffectScrollLoc(bool checked);

    void dbusServiceRegistered(const QString &serviceName);
    void dbusServiceUnregistered(const QString &serviceName);
private:
    Ui::RazerDriversKcmUi ui_main;
    Ui::DaemonNotAvailable ui_error;
    void setupUi();
    void setupErrorUi();

    QPair<librazer::Device*, QString> commonCombo(int index);
    QPair<librazer::Device*, QString> commonCombo(int index, QComboBox *sender);
    void getRazerDevices(void);
    QColor getColorForButton(int num, librazer::Device::lightingLocation location);
    const int getWaveDirection();
    void fillList();
    void showError(QString error);
    void showInfo(QString info);

    bool syncDpi = true;

    QHash<QString, librazer::Device*> devices;
};


#endif
