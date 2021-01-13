#include "TestIO.h"

#include <command/ICommand.h>
#include <memory>
#include <utility>

using namespace avansync;

class TestConnection : public IConnection {
private:
    std::unique_ptr<TestIO> _io = std::make_unique<TestIO>();
    bool _open {true};

public:
    TestIO& getIO() const override {
        return *_io;
    }

    void close() override {
        _open = false;
    }

    bool isOpen() const override {
        return _open;
    }

    std::string basedir() const override {
        return "./test-storage/";
    }
};