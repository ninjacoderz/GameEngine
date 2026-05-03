//
// Created by Binh Nguyen Thanh on 1/5/26.
//

#include "InputSystem.h"
#include <SDL3/SDL.h>

bool KeyboardState::GetKeyValue(SDL_Scancode key) const {
    return mCurrState[key] == 1;
}

ButtonState KeyboardState::GetKeyState(SDL_Scancode key) const {
    if (mPrevState[key] == 0)
    {
        if (mCurrState[key] == 0)
        {
            return ENone;
        }
        else
        {
            return EPressed;
        }
    }
    // Prev state must be 1
    if (mCurrState[key] == 0)
    {
        return EReleased;
    }
    return EHeld;
}

bool MouseState::GetButtonValue(int button) const {
    return (SDL_BUTTON_MASK(button) & mCurrButtons);
}

bool InputSystem::Initialize() {
    mState.Keyboard.mCurrState = SDL_GetKeyboardState(nullptr);
    memset(mState.Keyboard.mPrevState, 0,
        SDL_SCANCODE_COUNT);

    return true;
}

void InputSystem::Shutdown() {
}

void InputSystem::PrepareForUpdate() {
    // Copy current state to previous
    // Keyboard
    memcpy(mState.Keyboard.mPrevState,
        mState.Keyboard.mCurrState,
        SDL_SCANCODE_COUNT);

    // Mouse
    mState.Mouse.mPrevButtons = mState.Mouse.mCurrButtons;
    mState.Mouse.mScrollWheel = Vector2::Zero;
}

void InputSystem::Update() {
    // Mouse
    float x = 0, y = 0;
    if (mState.Mouse.mIsRelative)
    {
        mState.Mouse.mCurrButtons =
            SDL_GetRelativeMouseState(&x, &y);
    }
    else
    {
        mState.Mouse.mCurrButtons =
            SDL_GetMouseState(&x, &y);
    }

    mState.Mouse.mMousePos.x = x;
    mState.Mouse.mMousePos.y = y;
}

void InputSystem::ProcessEvent(union SDL_Event &event) {
    switch (event.type)
    {
        case SDL_EVENT_MOUSE_WHEEL:
            mState.Mouse.mScrollWheel = Vector2(
                static_cast<float>(event.wheel.x),
                static_cast<float>(event.wheel.y));
            break;
        default:
            break;
    }
}

void InputSystem::SetRelativeMouseMode(SDL_Window *window, bool value) {
    SDL_SetWindowRelativeMouseMode(window, value);
    mState.Mouse.mIsRelative = value;
}
