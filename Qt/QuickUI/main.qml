import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.1 //控制组件
import Qt.labs.platform 1.0 //不添加 菜单不出现

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("Hello World")

    //定时器刷新时间
    Timer{
        interval: 500
        running: true;repeat: true;
        onTriggered: time.text = Date().toString()
    }
    Text {
        id: time
    }


    MenuBar {
        Menu {
            id: fileMenu
            title: qsTr("File")
            // ...
        }
    }

    Button{
        id:btn1
        text: qsTr("heelo")
        //anchors.horizontalCenter: parent.horizontalCenter
        //anchors.verticalCenter: parent.verticalCenter
        x:300
        y:300
        /*onClicked: {
            function moveTo()
            {
                btn1.x = 350;
                btn1.y = 350;
            }
        }*/
        Menu{
            MenuItem{text: qsTr("Item1")}
            MenuItem{text: qsTr("Item2")}
        }
    }

    Rectangle{
        id:rect
        width: 150
        height: 150
        border.color: "red"
        border.width: 20
        radius: 15//设置弧度
        x:100
        y:100
        //定义信号
        signal deactivated
        MouseArea{//信号处理机制  鼠标点击事件  鼠标事件
            id:mouseArea
            anchors.fill: parent
            /*onClicked: {
               // Qt.quit();
                //onPressed:rect.deactivated()
                rect.color = Qt.rgba(Math.random(),
                                     Math.random(),
                                     Math.random(),1)
            }*/
        }
        color: "red"



    }

    Text {
        id:text
        anchors.centerIn: parent
        text: qsTr("text")
        font.family: "Helvetica"
        font.pointSize: 24
        color: "red"
    }
    Text {
        id: text1
        x:50
        y:50
        text: "<b>hello</b><i>world</i>"//world是斜体
    }

    //信号连接槽函数
    Connections
    {
        target: mouseArea
        onClicked: {
            rect.color = Qt.rgba(Math.random(),
                                 Math.random(),
                                 Math.random(),1)

        }
    }



    GroupBox{
        title: qsTr("check");checkable: true
        x:300;y:10;width: 200;height: 100
        Column{
            spacing:2
            CheckBox{text: qsTr("11")}
            CheckBox{text: qsTr("12")}
            CheckBox{text: qsTr("13")}
            Button{text: qsTr("btn")}
        }
    }

    //忙等待
    BusyIndicator{
        id:busy;running: true
        x:50
        y:100
    }
    MouseArea{
        //anchors.fill: parent
       // onClicked: busy.running = false
    }

    //Tab
    TabView{
        //anchors.fill: parent
        width: 120
        height: 80
        x:400
        y:400
        Tab{title:"home"}
        Tab{title:"home1"}
    }

}
