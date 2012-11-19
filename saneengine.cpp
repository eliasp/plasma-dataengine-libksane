/*
 * A KDE Plasma dataengine to access SANE scanners via libksane
 * Copyright 2012 Elias Probst <mail@eliasprobst.eu>
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
 */

#include <QList>
#include <QMap>
#include "saneengine.h"

#include <libksane/ksane.h>

void SaneEngine::init() {
    setData(
        QLatin1String("Scanners"),
        QLatin1String("default"),
        QLatin1String("default SANE scanner")
    );
    setData(
        QLatin1String("Scanners"),
        QLatin1String("net:homeserver:genesys:libusb:001:007"),
        QLatin1String("Canon LiDE 210")
    );
};

SaneEngine::SaneEngine(QObject* parent, const QVariantList& args)
    : Plasma::DataEngine(parent, args)
{
    // We ignore any arguments - data engines don't have any use for them
    Q_UNUSED(args)

    // This prevents applet from setting a way too high update interval and
    // using too much system resources.
    // This means, an update can only be done every 0.5 seconds
    setMinimumPollingInterval(500);
};

QStringList SaneEngine::sources() const
{
    return QStringList() << "Scanners";
}


bool SaneEngine::sourceRequestEvent(const QString &name)
{
    // We don't have any special code to execute the first time a source is
    // requested, so we just call updateSourceEvent().
    return updateSourceEvent(name);
}

bool SaneEngine::updateSourceEvent(const QString &operation)
{
    //QString scannerlist;

    if (operation == I18N_NOOP("Scanners")) {

        // reset the list of scanners
        removeAllData(QLatin1String("Scanners"));

        // get all available scanners from libksane
        QList<KSaneIface::KSaneWidget::DeviceInfo> deviceList;

        for (int i=0; i<deviceList.size(); i++) {
            kDebug() << "name: " << deviceList[i].name;
        }
        //kDebug() << "deviceList: " << deviceList;
        //Q_FOREACH ( const 

        //return QStringList() << "default" << "Epson LIDA 210" << "SANE dummy";
        return true;
    }
    else {
        return true;
    }
}

K_EXPORT_PLASMA_DATAENGINE(libksane, SaneEngine)

#include "saneengine.moc"
