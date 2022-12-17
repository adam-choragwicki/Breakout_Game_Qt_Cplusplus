#pragma once

#include <QString>

enum class GameResult
{
    NO_RESULT_YET, WIN, LOSE
};

class GameResultManager
{
public:
    GameResultManager();

    [[nodiscard]] GameResult getGameResult() const
    { return gameResult_; }

    void setGameResult(GameResult gameResult)
    { gameResult_ = gameResult; }

    [[nodiscard]] QString getGameEndMessage() const;

    [[nodiscard]] bool isGameFinished() const;

private:
    GameResult gameResult_;
};
