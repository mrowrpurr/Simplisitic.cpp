import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello, Qt!")

    Label {
        anchors.centerIn: parent
        text: "Hello, Qt!"
    }
}
