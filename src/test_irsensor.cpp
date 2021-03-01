//Meine Sensor Bennenung: [Left][HalfLeft][LeftFromMiddle][MiddleLeft][MiddleRight][RightFromMiddle][HalfRight][Right]
//ich gehe davon aus dass der normale Speed beim geradeausfahren 200 ist
if ((LeftFromMiddle ==0) && (RightFromMiddle ==1))
{
    LeftMotor.setSpeed(200);
    RightMotor.setSpeed(190)
    //So wurde das in dem Tutorial gemacht... Wir haben dafür die Library nicht installiert und ich kenn den korrekten Command und Motornamen nicht also ja...
};
if ((LeftFromMiddle ==1) && (RightFromMiddle ==0))
{
    LeftMotor.setSpeed(190)
    RightMotor.setSpeed(200)
};
if ((HalfLeft ==0) && (HalfRight ==1))
{
    LeftMotor.setSpeed(200);
    RightMotor.setSpeed(180)
};
if ((HalfLeft ==1) && (HalfRight ==0))
{
    LeftMotor.setSpeed(180);
    RightMotor.setSpeed(200)
};
if ((Left ==0) && (Right ==1))
{
    LeftMotor.setSpeed(200);
    RightMotor.setSpeed(170)
};
if ((Left ==1) && (Right ==0))
{
    LeftMotor.setSpeed(170);
    RightMotor.setSpeed(200)
}