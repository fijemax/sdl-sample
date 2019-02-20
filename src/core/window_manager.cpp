#include "core/window_manager.hpp"

#include "graphic/texture.hpp"
#include "graphic/sprites_loader.hpp"
#include "graphic/sprite.hpp"

#include "util/timer.hpp"

int WindowManager::start()
{
    mWindow = SDL_CreateWindow("SDL Sample Game",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               1024,
                               512,
                               SDL_WINDOW_SHOWN);
    if (!mWindow)
    {
        fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
        return -1;
    }

    mSceneRenderer = SDL_CreateRenderer(mWindow,
                                        -1,
                                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!mSceneRenderer)
    {
        fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
        return -1;
    }

    // =============
    // Load textures
    // =============
    vector<TextureDef> textureDefs = {{NIGHT, "bg_night.png"}};
    mTexturesLoader = new TexturesLoader(mSceneRenderer, *mAssetsPath, textureDefs);
    if (!mTexturesLoader->loads())
    {
        fprintf(stderr, "Erreur de chargement des textures: %s\n", SDL_GetError());
        return -1;
    }

    // ============
    // Load sprites
    // ============
    vector<SpriteDef> spritesDefs = {{FIRST, "foo.png", 1, 4, 500},
                                     {SECOND, "foo2.png", 1, 3, 500},
                                     {THIRD, "foo3.png", 2, 4, 500},
                                     {FOURTH, "foo4.png", 4, 4, 500}};
    mSpritesLoader = new SpritesLoader(mSceneRenderer, *mAssetsPath, spritesDefs);
    if (!mSpritesLoader->loads())
    {
        fprintf(stderr, "Erreur de chargement des sprites: %s\n", SDL_GetError());
        return -1;
    }

    SDL_SetRenderDrawColor(mSceneRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(mSceneRenderer);
    SDL_RenderPresent(mSceneRenderer);

    return 0;

    /*
    // ##########
    //   Box2D
    // ##########
    b2Vec2 gravity(0.0f, -9.8f);
    b2World world(gravity);

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(5.0f, -10.0f);

    b2Body *groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(40.0f, 0.0f);
    b2Body *body = world.CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
    b2Vec2 b2Velocity(-10.0f, 0.0f);

    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    if (pWindow)
    {
        SpritesLoader spriteLoader(pMainRenderer, *mAssetsPath);

        // string sprite_path = (*mAssetsPath).append("foo3.png");

        int frame = 0;
        Timer the_timer;
        if (spriteLoader.loads())
        {
            SDL_Event e;
            mRun = true;

            while (mRun)
            {
                int move = 0;
                int jump = 0;
                int factor = 1;
                while (SDL_PollEvent(&e) != 0)
                {
                    switch (e.type)
                    {
                    case SDL_QUIT:
                        mRun = false;
                        break;
                    case SDL_KEYUP:
                        factor = -10;
                    case SDL_KEYDOWN:
                        switch (e.key.keysym.sym)
                        {
                        case SDLK_LEFT:
                            move = -80 * factor;
                            break;
                        case SDLK_RIGHT:
                            move = 80 * factor;
                            break;
                        case SDLK_UP:
                            jump = 2000;
                            break;
                        default:
                            break;
                        }
                    default:
                        break;
                    }
                }
                SDL_SetRenderDrawColor(pMainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(pMainRenderer);
                // SDL_Rect rect = {0, 0, SDL_GetWindowSurface(pWindow)->w, SDL_GetWindowSurface(pWindow)->h};
                // texture.render(0, 0, &rect);

                int frame_divider = 5;
                Sprite *sprite = spriteLoader.get(3);

                // ##########
                //   Box2D
                // ##########
                if (move != 0)
                {
                    body->ApplyForceToCenter(b2Vec2(move, 0), true);
                }
                if (jump != 0)
                {
                    body->ApplyForceToCenter(b2Vec2(0, jump), true);
                }
                world.Step(timeStep, velocityIterations, positionIterations);

                b2Vec2 position = body->GetPosition();
                float32 angle = body->GetAngle();
                int x = position.x * 500 / 50;
                int y = 500 - (position.y * 500 / 40) - 125;

                fprintf(stdout, "%4.2f %4.2f %4.2f %4.2d %4.2d\n", position.x, position.y, angle, x, y);

                sprite->render(x, y, frame / frame_divider);
                ++frame;
                if (frame / frame_divider >= sprite->getSpriteClipsNumber())
                {
                    frame = 0;
                }
                SDL_RenderPresent(pMainRenderer);

                // Print frequency
                // float t = the_timer.getTicks();
                // if (t > 0)
                //     fprintf(stdout, "\r Frequency: %f", 1 / (t / 1000));
                the_timer.start();
            }
        }
        SDL_DestroyWindow(pWindow);
    }
    else
    {
        fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
    }
*/
    return 0;
}

int WindowManager::renderScene(int timestamp)
{
    if (!mWindow || !mSceneRenderer)
        return -1;
    SDL_RenderClear(mSceneRenderer);
    SDL_SetRenderDrawColor(mSceneRenderer, 0x2F, 0x3D, 0x67, 0xFF);

    int x, y;
    mScene.getCenter(x, y);
    fprintf(stdout, "%d %d\n", x, y);

    mTexturesLoader->render(NIGHT, 0, 0, NULL, 0, NULL, SDL_FLIP_NONE);

    // mSpritesLoader->render(THIRD, timestamp, 150, 0, 45, NULL, SDL_FLIP_NONE);
    mSpritesLoader->render(SECOND, timestamp, 0, 0, 0, NULL, SDL_FLIP_NONE);
    // mSpritesLoader->render(FOURTH, timestamp, 150, 0, 0, NULL, SDL_FLIP_NONE);
    mSpritesLoader->render(FOURTH, timestamp / 2, 300, 0, 0, NULL, SDL_FLIP_NONE);

    SDL_RenderPresent(mSceneRenderer);

    return 0;
}

void WindowManager::stop()
{
    if (mSpritesLoader)
    {
        delete mSpritesLoader;
    }

    if (mTexturesLoader)
    {
        delete mTexturesLoader;
    }

    if (mSceneRenderer)
    {
        SDL_DestroyRenderer(mSceneRenderer);
    }

    if (mWindow)
    {
        SDL_DestroyWindow(mWindow);
    }

    mTexturesLoader = NULL;
    mSpritesLoader = NULL;
    mWindow = NULL;
    mSceneRenderer = NULL;
}