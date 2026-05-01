//
// Created by Binh Nguyen Thanh on 1/5/26.
//

#ifndef ASTEROID_INPUTSYSTEM_H
#define ASTEROID_INPUTSYSTEM_H
#include "Math.h"
#include <SDL3/SDL.h>


enum ButtonState
{
    ENone,
    EPressed,
    EReleased,
    EHeld
};

class KeyboardState {
public:
    friend class InputSystem;
    bool GetKeyValue(SDL_Scancode key) const;
    ButtonState GetKeyState(SDL_Scancode key) const;
private:
    const bool* mCurrState;
    bool mPrevState[SDL_SCANCODE_COUNT];
};

class MouseState
{
public:
    friend class InputSystem;

    // For mouse position
    const Vector2& GetPosition() const { return mMousePos; }
    const Vector2& GetScrollWheel() const { return mScrollWheel; }
    bool IsRelative() const { return mIsRelative; }

    // For buttons
    bool GetButtonValue(int button) const;
    ButtonState GetButtonState(int button) const;
private:
    // Store the current mouse position
    Vector2 mMousePos;
    // Motion of the scroll wheel
    Vector2 mScrollWheel;
    // Store button data
    Uint32 mCurrButtons;
    Uint32 mPrevButtons;
    // Are we in relative mouse mode?
    bool mIsRelative;
};

struct InputState {
    KeyboardState Keyboard;
    MouseState Mouse;
};

class InputSystem {
public:
    bool Initialize();
    void Shutdown();

    void PrepareForUpdate();
    void Update();
    void ProcessEvent(union SDL_Event& event);
    const InputState& GetState() const { return mState; }

    void SetRelativeMouseMode(SDL_Window* window, bool value);
private:
    InputState mState;
};


#endif //ASTEROID_INPUTSYSTEM_H