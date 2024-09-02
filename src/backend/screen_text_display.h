#pragma once

#include <QtWidgets/QGraphicsTextItem>

class GameManager;

class ScreenTextDisplay : public QGraphicsTextItem
{
public:
    explicit ScreenTextDisplay();
    ~ScreenTextDisplay() override = default;

    void setGameManager(GameManager* gameManager)
    { gameManager_ = gameManager; }

private:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private:
    GameManager* gameManager_{};

    const QPen penRed_{Qt::red};
    const QPen penYellow_{Qt::yellow};
    const QPen penWhite_{Qt::white};

    QFont font_;
};
