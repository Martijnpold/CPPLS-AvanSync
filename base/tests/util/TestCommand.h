#include <command/ICommand.h>
#include <utility>

using namespace avansync;

class TestCommand : public ICommand {
private:
    std::string _message;

public:
    explicit TestCommand(const std::string& message) : _message {message} {
    }

    void execute(IO& systemIO, IConnection& connection) const override {
        systemIO.writeString(_message);
        connection.getIO().writeString(_message);
    }
};