#include <buffer/ListIO.h>
#include <command/ICommand.h>
#include <memory>
#include <utility>

using namespace avansync;

class TestConnection : public IConnection {
private:
    std::unique_ptr<ListIO> _io = std::make_unique<ListIO>();

public:
    IO& getIO() const override {
        return *_io;
    }

    void close() override {
    }

    bool isOpen() const override {
        return true;
    }

    std::string basedir() const override {
        return "./test-storage/";
    }
};