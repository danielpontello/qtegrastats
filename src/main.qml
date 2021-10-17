import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("qtegrastats")
    //flags: Qt.WindowStaysOnBottomHint | Qt.FramelessWindowHint;
    color: "#000000"

    Column {
        id: column
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        anchors.bottomMargin: 20
        anchors.topMargin: 20
        anchors.fill: parent

        Row {
            id: cpu_title_row

            Text {
                id: title_text
                color: "#ffffff"
                text: "CPU"
                font.pixelSize: 36
            }
        }

        Row {
            id: cpu_row
            height: 400
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0

            Grid {
                id: cores_grid
                width: 120
                height: 120
                rows: 2
                columns: 2

                Text {
                    id: core_1
                    width: 60
                    height: 60
                    color: "#ffffff"
                    text: tegraStats.cpu0
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 18
                    anchors.rightMargin: 10
                    anchors.leftMargin: 10
                    anchors.bottomMargin: 10
                    anchors.topMargin: 10
                }

                Text {
                    id: core_2
                    width: 60
                    height: 60
                    color: "#ffffff"
                    text: tegraStats.cpu1
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 18
                    anchors.rightMargin: 10
                    anchors.leftMargin: 10
                    anchors.bottomMargin: 10
                    anchors.topMargin: 10
                }

                Text {
                    id: core_3
                    width: 60
                    height: 60
                    color: "#ffffff"
                    text: tegraStats.cpu2
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 18
                    anchors.rightMargin: 10
                    anchors.leftMargin: 10
                    anchors.bottomMargin: 10
                    anchors.topMargin: 10
                }

                Text {
                    id: core_4
                    width: 60
                    height: 60
                    color: "#ffffff"
                    text: tegraStats.cpu3
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 18
                    anchors.rightMargin: 10
                    anchors.leftMargin: 10
                    anchors.bottomMargin: 10
                    anchors.topMargin: 10
                }
            }

            Canvas {
                id: chart_canvas;
            }
        }


    }

    Flow {
        id: main_flow
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        anchors.bottomMargin: 20
        anchors.topMargin: 20
        anchors.fill: parent
    }

}
