#pragma once

#include <QObject>
#include <QTimer>

class Model;
class QTimer;

enum class GameResult;

class GameLoop : public QObject
{
Q_OBJECT

signals:
    void endGame(GameResult gameResult);

public:
    explicit GameLoop(Model& model);
    void start();
    void stop();

private slots:
    void execute();

private:
    void checkAndProcessBallCollisions();

    void checkAndProcessBallCollisionWithArenaEdges(const QRect& ballRect);
    void checkAndProcessBallCollisionWithBrick(const QRect& ballRect);
    void checkAndProcessBallCollisionWithPaddle(const QRect& ballRect);

    Model& model_;

    std::unique_ptr<QTimer> gameLoopTimer_;

    static constexpr auto GAME_LOOP_INTERVAL = std::chrono::milliseconds(3);

    long long loopCounter_{};
};
