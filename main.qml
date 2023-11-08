import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 300
    height: 200
    title: "Number Dropdown"

    ColumnLayout {
        spacing: 10
        anchors.centerIn: parent

        ComboBox {
            id: numberDropdown
            width: 100
            Layout.alignment: Qt.AlignHCenter
            model: DropDownSample.dropdownElements // Use the dropdownElements property
            onActivated: {
                DropDownSample.onDropDownValueChanged(numberDropdown.currentIndex)
            }
        }

        Button {
            text: "Add New Element"
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                DropDownSample.addNewElement()
            }
        }
    }
}
