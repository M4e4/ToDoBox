// #include "editingwidget.h"
// #include "approvedwidget.h"

// #include <QHBoxLayout>
// #include <QCheckBox>
// #include <QComboBox>
// #include <QPushButton>
// #include <QLineEdit>
// #include <QDateEdit>
// #include <QTimer>

// #include "utils/utils.h"





// EditingWidget::EditingWidget(TaskList *list, QListWidgetItem *item, QWidget *parent) : QWidget{parent}
// {
//     setFixedHeight(itemHeight);
//     setAttribute(Qt::WA_StyledBackground, true);
//     setStyleSheet("EditingWidget {background: #555555; border-radius: 5px;}");

//     QWidget* widget {list->itemWidget(item)};

//     if (widget)
//     {
//         list->removeItemWidget(item);
//         delete widget;
//     }

//     // Layouts.
//     QHBoxLayout* mainHLayout {new QHBoxLayout(this)};
//     QHBoxLayout* buttonHLayout {new QHBoxLayout};

//     // Icon status.
//     QPushButton* bIcon {new QPushButton};
//     bIcon->setStyleSheet("QPushButton {border: none; }");
//     bIcon->setFixedSize(30,30);
//     bIcon->setIconSize(QSize(20,20));
//     bIcon->setIcon(list->getIcon(static_cast<Status>(item->data(toInt(Role::F_STATUS)).toInt())));
//     bIcon->setFlat(true);

//     // Title edit.
//     QLineEdit* title {new QLineEdit(item->data(toInt(Role::TITLE)).toString())};
//     title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//     // title->setPlaceholderText("Enter the task name");
//     title->setPlaceholderText("Введите название задачи");
//     title->setMaxLength(100);
//     title->setStyleSheet("QLineEdit {color: white; background: transparent; border: none;}");
//     QTimer::singleShot(0, this, [title]() { title->setFocus(); });

//     // Date edit.
//     QDateEdit* date{new QDateEdit};
//     date->setStyleSheet("QDateEdit {color: white; background: transparent; border: none;}");
//     date->setDate(QDate::fromString(item->data(toInt(Role::DATE)).toString(), "dd.MM.yyyy"));
//     date->setDisplayFormat("dd.MM.yyyy");
//     date->setCalendarPopup(true);

//     // Auto save.
//     QTimer* autoSaveTimer {new QTimer};
//     autoSaveTimer->setSingleShot(true);

//     auto save {[item, title, date]()
//         {
//             if (item->data(toInt(Role::TITLE)).toString() == title->text() &&
//                 item->data(toInt(Role::DATE)).toString() == date->text() ||
//                 title->text().trimmed().isEmpty()) return;

//             QDate currDate {QDate::currentDate()};
//             Status actualStatus {date->date() == currDate ? Status::ACTUAL :
//                                  date->date() >  currDate ? Status::QUEUE :
//                                  Status::OVERDUE};

//             item->setData(toInt(Role::B_STATUS), toInt(actualStatus));
//             item->setData(toInt(Role::F_STATUS), toInt(actualStatus));
//             item->setData(toInt(Role::TITLE), title->text());
//             item->setData(toInt(Role::DATE), date->text());
//         }};
//     connect(autoSaveTimer, &QTimer::timeout, this, save);
//     connect(title, &QLineEdit::textChanged, title, [autoSaveTimer]()
//             {
//                 autoSaveTimer->start(1500);
//             });
//     connect(date, &QDateEdit::dateChanged, date, [autoSaveTimer]()
//             {
//                 autoSaveTimer->start(1500);
//             });

//     // Button done.
//     QPushButton* bDone {new QPushButton(QIcon(":/icons/icon-button-done.png"),"")};
//     bDone->setIconSize(QSize(12,12));
//     bDone->setStyleSheet(R"(
//     QPushButton
//     {
//         background: #777;
//         color: white;
//         border: none;
//     }
//     QPushButton:disabled
//     {
//         background: #555555;
//     })");
//     bDone->setFixedSize(45,30);
//     bDone->setEnabled(!title->text().isEmpty());

//     connect(title, &QLineEdit::textChanged, this, [bDone](QString text)
//             {
//                 bDone->setEnabled(!text.trimmed().isEmpty());
//             });
//     connect(title, &QLineEdit::returnPressed, bDone, &QPushButton::click);
//     connect(bDone, &QPushButton::clicked, this, [this, list, item, save]()
//             {
//                 save();

//                 ApprovedWidget* approvedWidget {new ApprovedWidget(list, item)};

//                 list->setItemWidget(item, approvedWidget);
//                 list->setCurrentItem(item);
//                 list->setFocus();

//                 delete this;
//             });

//     // Button delete.
//     QPushButton* bDelete {new QPushButton(QIcon(":/icons/icon-button-delete.png"),"")};
//     bDelete->setStyleSheet(R"(
//     QPushButton
//     {
//         background: #d04040;
//         color: white;
//         border: none;
//         border-top-right-radius: 5px;
//         border-bottom-right-radius: 5px;
//     })");
//     bDelete->setFixedSize(45,30);

//     connect(bDelete, &QPushButton::clicked, this, [this, list, item]()
//             {
//                 int index {list->row(item)};
//                 list->takeItem(index);

//                 delete item;
//                 delete this;
//             });





//     mainHLayout->setContentsMargins(0,0,0,0);
//     mainHLayout->setSpacing(0);
//     mainHLayout->addWidget(bIcon);
//     mainHLayout->addWidget(title);
//     mainHLayout->addSpacing(10);
//     mainHLayout->addWidget(date);
//     mainHLayout->addLayout(buttonHLayout);


//     buttonHLayout->setContentsMargins(0,0,0,0);
//     buttonHLayout->setSpacing(0);
//     buttonHLayout->addWidget(bDone);
//     buttonHLayout->addWidget(bDelete);
// }
