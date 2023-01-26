/****************************************************************************
** Meta object code from reading C++ file 'songdialog.h'
**
** Created: Fri Apr 8 14:37:03 2022
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qdemo/songdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'songdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SongDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      31,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      80,   11,   11,   11, 0x08,
     106,   11,   11,   11, 0x08,
     130,   11,   11,   11, 0x08,
     154,   11,   11,   11, 0x08,
     182,   11,   11,   11, 0x08,
     212,   11,   11,   11, 0x08,
     236,   11,   11,   11, 0x08,
     260,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SongDialog[] = {
    "SongDialog\0\0handleCommand(int)\0"
    "on_pauseButton_clicked()\0"
    "on_playButton_clicked()\0"
    "on_dotoriButton_clicked()\0"
    "on_skipButton_clicked()\0on_exitButton_clicked()\0"
    "on_volumeupButton_clicked()\0"
    "on_volumedownButton_clicked()\0"
    "on_stopButton_clicked()\0on_openButton_clicked()\0"
    "on_albumWidget_destroyed()\0"
};

void SongDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SongDialog *_t = static_cast<SongDialog *>(_o);
        switch (_id) {
        case 0: _t->handleCommand((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pauseButton_clicked(); break;
        case 2: _t->on_playButton_clicked(); break;
        case 3: _t->on_dotoriButton_clicked(); break;
        case 4: _t->on_skipButton_clicked(); break;
        case 5: _t->on_exitButton_clicked(); break;
        case 6: _t->on_volumeupButton_clicked(); break;
        case 7: _t->on_volumedownButton_clicked(); break;
        case 8: _t->on_stopButton_clicked(); break;
        case 9: _t->on_openButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SongDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SongDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SongDialog,
      qt_meta_data_SongDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SongDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SongDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SongDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SongDialog))
        return static_cast<void*>(const_cast< SongDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SongDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
