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

#ifndef SANEENGINE_H
#define SANEENGINE_H

#include <plasma/dataengine.h>

class SaneEngine : public Plasma::DataEngine
{
    // required since Plasma::DataEngine inherits QObject
    Q_OBJECT

    public:
        // every engine needs a constructor with these arguments
        SaneEngine(QObject* parent, const QVariantList& args);

        // inherited from Plasma::DataEngine, lists the datasources provided
        // by this data engine
        virtual QStringList sources() const;

    protected:
        // this virtual function is called when a new source is requested
        //virtual QStringList sourceRequestEvent(const QString& name);

        // this virtual function is called when an automatic update is
        // triggered for an existing source (ie: when a valid update
        // interval is set when requesting a source)
        //virtual QStringList updateSourceEvent(const QString& source);
};

#endif // SANEENGINE_H

