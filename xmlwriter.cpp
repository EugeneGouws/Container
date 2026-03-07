#include "xmlwriter.h"
#include <QDomDocument>
#include <QMetaProperty>
#include <qdebug.h>
#include "palletlist.h"
#include "pallet.h"

XmlWriter::XmlWriter() {}

QByteArray XmlWriter::writeXml()
{
    //Create the document and allocate a root
    QDomDocument doc;
    QDomElement root = doc.createElement("Pallets");


    //get the list and add nodes
    PalletList *pallets = PalletList::getInstance();

    root.setAttribute("NumberOfPallets", pallets->getList().length());
    doc.appendChild(root);

    //add pallets
    for (Pallet *p : pallets->getList())
    {
        QDomElement node1 = doc.createElement("Pallet");
        node1.setAttribute("Weight", p->getWeight());
        node1.setAttribute("Volume", p->getVolume());
        node1.setAttribute("Number", p->getNumber());
        root.appendChild(node1);
        qDebug()<<"Appended pallet: "<<p->getNumber();

        //add containers
        for (Container *c : p->getList())
        {
            const QMetaObject* metaObj = c->metaObject();
            QDomElement node2 = doc.createElement(metaObj->className());
            node1.appendChild(node2);

            //cycle through attributes

            for (int i = metaObj->propertyOffset(); i < metaObj->propertyCount(); ++i)
            {
                QMetaProperty prop = metaObj->property(i);
                QString propName = prop.name();
                QVariant value = prop.read(c);

                // Skip invalid or empty values if needed
                if (!value.isValid()) continue;

                QDomElement node3 = doc.createElement(propName);
                QDomText textNode = doc.createTextNode(value.toString());
                node3.appendChild(textNode);
                node2.appendChild(node3);

            }
        }
    }
    QByteArray data;
    data.append(doc.toByteArray());
    return data;
}
