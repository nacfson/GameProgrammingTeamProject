#pragma once
#include "Collider.h"
#include "Object.h"
#include "Slider.h"
class Rigidbody2D;
class Raycast2D;
class Texture;
class Slider;
class RayCollider;


class Player :
    public Object
{
public:
    Player();
    Player(Player& player);
    ~Player();
public:
    void Init();

    void Update() override;
    void Render(HDC _dc) override;
    void FinalUpdate() override;
    
    void EnterCollision(Collider* _pOther) override;
    void ExitCollision(Collider* _pOther) override;
    void StayCollision(Collider* _pOther) override;

    void EnterCollision(Collider* _pOther, ERAY_DIR _dir ) ;
    void ExitCollision(Collider* _pOther,  ERAY_DIR _dir) ;
    void StayCollision(Collider* _pOther,  ERAY_DIR _dir) ;

    //void 

    void SetSlider(Slider* _pSlider)
    {
        m_pSlider = _pSlider;

        //This can make error when m_fMaxJumPower not defined early
        m_pSlider->SetValues(m_fMinJumpPower,m_fMaxJumpPower);
    }
private:
    void CreateBullet();
private:
    Texture* m_pTex;
    Texture* m_pTexL;
    Texture* m_pTexR;

    Rigidbody2D* m_pRigidbody2D;
    Slider* m_pSlider;

    bool m_bCanMove;


    float m_fMinJumpPower;
    float m_fMaxJumpPower;
    float m_fPlusJumpPower;
    float m_fCurJumpPower;

    KEY_TYPE m_prevPressMoveKey;
    DIRECTION_TYPE m_curDir;
};

