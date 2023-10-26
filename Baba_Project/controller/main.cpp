
#define RUN_TEST 0
#define GRAPHIC 1

#if RUN_TEST
#define CATCH_CONFIG_RUNNER
#include "../catch2/catch.hpp"

int main( int argc, char* argv[] ) {
  // global setup...

  int result = Catch::Session().run( argc, argv );

  // global clean-up...

  return result;
}



#else
    #include "Controller.h"
    #include <cstring>
    #include <iostream>

    using namespace std;


#if !GRAPHIC
    #include "../view/View.h"
    int main()
    {
        Game game = Game();
        game.setUpRules();
        Controller c = Controller(game);
        View view  = View(game, c);
        view.start();
    }
#else
    #include "../view/mainwindow.h"
    #include <QApplication>
    int main(int argc, char *argv[])
    {
        Game game = Game();
        game.setUpRules();
        QApplication a(argc, argv);
        Controller c = Controller(game);
        MainWindow w = MainWindow(game,c);
        w.show();
        return a.exec();
    }
#endif

#endif

