// JavaC16XCompiler.cpp: implementation of the CJavaC16XCompiler class.
//
//////////////////////////////////////////////////////////////////////

#include "JavaC16XCompiler.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

__JAVA_C16X_BEGIN

CJavaC16XCompiler::CJavaC16XCompiler(CJavaC16XTarget* _target):
m_ptTarget(_target)
{

}

CJavaC16XCompiler::~CJavaC16XCompiler()
{

}

void CJavaC16XCompiler::Analisys(CTree* root) throw(CPeterCompiler::CSemanticException)
{
	bool std_analisys=true;
	switch(root->m_iRule)
	{
	case 1:
		std_analisys=SemanticItem1(root);
		break;
	case 2:
		std_analisys=SemanticItem2(root);
		break;
	case 3:
		std_analisys=SemanticItem3(root);
		break;
	case 4:
		std_analisys=SemanticItem4(root);
		break;
	case 5:
		std_analisys=SemanticItem5(root);
		break;
	case 6:
		std_analisys=SemanticItem6(root);
		break;
	case 7:
		std_analisys=SemanticItem7(root);
		break;
	case 8:
		std_analisys=SemanticItem8(root);
		break;
	case 9:
		std_analisys=SemanticItem9(root);
		break;
	case 10:
		std_analisys=SemanticItem10(root);
		break;
	case 11:
		std_analisys=SemanticItem11(root);
		break;
	case 12:
		std_analisys=SemanticItem12(root);
		break;
	case 13:
		std_analisys=SemanticItem13(root);
		break;
	case 14:
		std_analisys=SemanticItem14(root);
		break;
	case 15:
		std_analisys=SemanticItem15(root);
		break;
	case 16:
		std_analisys=SemanticItem16(root);
		break;
	case 17:
		std_analisys=SemanticItem17(root);
		break;
	case 18:
		std_analisys=SemanticItem18(root);
		break;
	case 19:
		std_analisys=SemanticItem19(root);
		break;
	case 20:
		std_analisys=SemanticItem20(root);
		break;
	case 21:
		std_analisys=SemanticItem21(root);
		break;
	case 22:
		std_analisys=SemanticItem22(root);
		break;
	case 23:
		std_analisys=SemanticItem23(root);
		break;
	case 24:
		std_analisys=SemanticItem24(root);
		break;
	case 25:
		std_analisys=SemanticItem25(root);
		break;
	case 26:
		std_analisys=SemanticItem26(root);
		break;
	case 27:
		std_analisys=SemanticItem27(root);
		break;
	case 28:
		std_analisys=SemanticItem28(root);
		break;
	case 29:
		std_analisys=SemanticItem29(root);
		break;
	case 30:
		std_analisys=SemanticItem30(root);
		break;
	case 31:
		std_analisys=SemanticItem31(root);
		break;
	case 32:
		std_analisys=SemanticItem32(root);
		break;
	case 33:
		std_analisys=SemanticItem33(root);
		break;
	case 34:
		std_analisys=SemanticItem34(root);
		break;
	case 35:
		std_analisys=SemanticItem35(root);
		break;
	case 36:
		std_analisys=SemanticItem36(root);
		break;
	case 37:
		std_analisys=SemanticItem37(root);
		break;
	case 38:
		std_analisys=SemanticItem38(root);
		break;
	case 39:
		std_analisys=SemanticItem39(root);
		break;
	case 40:
		std_analisys=SemanticItem40(root);
		break;
	case 41:
		std_analisys=SemanticItem41(root);
		break;
	case 42:
		std_analisys=SemanticItem42(root);
		break;
	case 43:
		std_analisys=SemanticItem43(root);
		break;
	case 44:
		std_analisys=SemanticItem44(root);
		break;
	case 45:
		std_analisys=SemanticItem45(root);
		break;
	case 46:
		std_analisys=SemanticItem46(root);
		break;
	case 47:
		std_analisys=SemanticItem47(root);
		break;
	case 48:
		std_analisys=SemanticItem48(root);
		break;
	case 49:
		std_analisys=SemanticItem49(root);
		break;
	case 50:
		std_analisys=SemanticItem50(root);
		break;
	case 51:
		std_analisys=SemanticItem51(root);
		break;
	case 52:
		std_analisys=SemanticItem52(root);
		break;
	case 53:
		std_analisys=SemanticItem53(root);
		break;
	case 54:
		std_analisys=SemanticItem54(root);
		break;
	case 55:
		std_analisys=SemanticItem55(root);
		break;
	case 56:
		std_analisys=SemanticItem56(root);
		break;
	case 57:
		std_analisys=SemanticItem57(root);
		break;
	case 58:
		std_analisys=SemanticItem58(root);
		break;
	case 59:
		std_analisys=SemanticItem59(root);
		break;
	case 60:
		std_analisys=SemanticItem60(root);
		break;
	case 61:
		std_analisys=SemanticItem61(root);
		break;
	case 62:
		std_analisys=SemanticItem62(root);
		break;
	case 63:
		std_analisys=SemanticItem63(root);
		break;
	case 64:
		std_analisys=SemanticItem64(root);
		break;
	case 65:
		std_analisys=SemanticItem65(root);
		break;
	case 66:
		std_analisys=SemanticItem66(root);
		break;
	case 67:
		std_analisys=SemanticItem67(root);
		break;
	case 68:
		std_analisys=SemanticItem68(root);
		break;
	case 69:
		std_analisys=SemanticItem69(root);
		break;
	case 70:
		std_analisys=SemanticItem70(root);
		break;
	case 71:
		std_analisys=SemanticItem71(root);
		break;
	case 72:
		std_analisys=SemanticItem72(root);
		break;
	case 73:
		std_analisys=SemanticItem73(root);
		break;
	case 74:
		std_analisys=SemanticItem74(root);
		break;
	case 75:
		std_analisys=SemanticItem75(root);
		break;
	case 76:
		std_analisys=SemanticItem76(root);
		break;
	case 77:
		std_analisys=SemanticItem77(root);
		break;
	case 78:
		std_analisys=SemanticItem78(root);
		break;
	case 79:
		std_analisys=SemanticItem79(root);
		break;
	case 80:
		std_analisys=SemanticItem80(root);
		break;
	case 81:
		std_analisys=SemanticItem81(root);
		break;
	case 82:
		std_analisys=SemanticItem82(root);
		break;
	case 83:
		std_analisys=SemanticItem83(root);
		break;
	case 84:
		std_analisys=SemanticItem84(root);
		break;
	case 85:
		std_analisys=SemanticItem85(root);
		break;
	case 86:
		std_analisys=SemanticItem86(root);
		break;
	case 87:
		std_analisys=SemanticItem87(root);
		break;
	case 88:
		std_analisys=SemanticItem88(root);
		break;
	case 89:
		std_analisys=SemanticItem89(root);
		break;
	case 90:
		std_analisys=SemanticItem90(root);
		break;
	case 91:
		std_analisys=SemanticItem91(root);
		break;
	case 92:
		std_analisys=SemanticItem92(root);
		break;
	case 93:
		std_analisys=SemanticItem93(root);
		break;
	case 94:
		std_analisys=SemanticItem94(root);
		break;
	case 95:
		std_analisys=SemanticItem95(root);
		break;
	case 96:
		std_analisys=SemanticItem96(root);
		break;
	case 97:
		std_analisys=SemanticItem97(root);
		break;
	case 98:
		std_analisys=SemanticItem98(root);
		break;
	case 99:
		std_analisys=SemanticItem99(root);
		break;
	case 100:
		std_analisys=SemanticItem100(root);
		break;
	case 101:
		std_analisys=SemanticItem101(root);
		break;
	case 102:
		std_analisys=SemanticItem102(root);
		break;
	case 103:
		std_analisys=SemanticItem103(root);
		break;
	case 104:
		std_analisys=SemanticItem104(root);
		break;
	case 105:
		std_analisys=SemanticItem105(root);
		break;
	case 106:
		std_analisys=SemanticItem106(root);
		break;
	case 107:
		std_analisys=SemanticItem107(root);
		break;
	case 108:
		std_analisys=SemanticItem108(root);
		break;
	case 109:
		std_analisys=SemanticItem109(root);
		break;
	case 110:
		std_analisys=SemanticItem110(root);
		break;
	case 111:
		std_analisys=SemanticItem111(root);
		break;
	case 112:
		std_analisys=SemanticItem112(root);
		break;
	case 113:
		std_analisys=SemanticItem113(root);
		break;
	case 114:
		std_analisys=SemanticItem114(root);
		break;
	case 115:
		std_analisys=SemanticItem115(root);
		break;
	case 116:
		std_analisys=SemanticItem116(root);
		break;
	case 117:
		std_analisys=SemanticItem117(root);
		break;
	case 118:
		std_analisys=SemanticItem118(root);
		break;
	case 119:
		std_analisys=SemanticItem119(root);
		break;
	case 120:
		std_analisys=SemanticItem120(root);
		break;
	case 121:
		std_analisys=SemanticItem121(root);
		break;
	case 122:
		std_analisys=SemanticItem122(root);
		break;
	case 123:
		std_analisys=SemanticItem123(root);
		break;
	case 124:
		std_analisys=SemanticItem124(root);
		break;
	case 125:
		std_analisys=SemanticItem125(root);
		break;
	case 126:
		std_analisys=SemanticItem126(root);
		break;
	case 127:
		std_analisys=SemanticItem127(root);
		break;
	case 128:
		std_analisys=SemanticItem128(root);
		break;
	case 129:
		std_analisys=SemanticItem129(root);
		break;
	case 130:
		std_analisys=SemanticItem130(root);
		break;
	case 131:
		std_analisys=SemanticItem131(root);
		break;
	case 132:
		std_analisys=SemanticItem132(root);
		break;
	case 133:
		std_analisys=SemanticItem133(root);
		break;
	case 134:
		std_analisys=SemanticItem134(root);
		break;
	case 135:
		std_analisys=SemanticItem135(root);
		break;
	case 136:
		std_analisys=SemanticItem136(root);
		break;
	case 137:
		std_analisys=SemanticItem137(root);
		break;
	case 138:
		std_analisys=SemanticItem138(root);
		break;
	case 139:
		std_analisys=SemanticItem139(root);
		break;
	case 140:
		std_analisys=SemanticItem140(root);
		break;
	case 141:
		std_analisys=SemanticItem141(root);
		break;
	case 142:
		std_analisys=SemanticItem142(root);
		break;
	case 143:
		std_analisys=SemanticItem143(root);
		break;
	case 144:
		std_analisys=SemanticItem144(root);
		break;
	case 145:
		std_analisys=SemanticItem145(root);
		break;
	case 146:
		std_analisys=SemanticItem146(root);
		break;
	case 147:
		std_analisys=SemanticItem147(root);
		break;
	case 148:
		std_analisys=SemanticItem148(root);
		break;
	case 149:
		std_analisys=SemanticItem149(root);
		break;
	case 150:
		std_analisys=SemanticItem150(root);
		break;
	case 151:
		std_analisys=SemanticItem151(root);
		break;
	case 152:
		std_analisys=SemanticItem152(root);
		break;
	case 153:
		std_analisys=SemanticItem153(root);
		break;
	case 154:
		std_analisys=SemanticItem154(root);
		break;
	case 155:
		std_analisys=SemanticItem155(root);
		break;
	case 156:
		std_analisys=SemanticItem156(root);
		break;
	case 157:
		std_analisys=SemanticItem157(root);
		break;
	case 158:
		std_analisys=SemanticItem158(root);
		break;
	case 159:
		std_analisys=SemanticItem159(root);
		break;
	case 160:
		std_analisys=SemanticItem160(root);
		break;
	case 161:
		std_analisys=SemanticItem161(root);
		break;
	case 162:
		std_analisys=SemanticItem162(root);
		break;
	case 163:
		std_analisys=SemanticItem163(root);
		break;
	case 164:
		std_analisys=SemanticItem164(root);
		break;
	case 165:
		std_analisys=SemanticItem165(root);
		break;
	case 166:
		std_analisys=SemanticItem166(root);
		break;
	case 167:
		std_analisys=SemanticItem167(root);
		break;
	case 168:
		std_analisys=SemanticItem168(root);
		break;
	case 169:
		std_analisys=SemanticItem169(root);
		break;
	case 170:
		std_analisys=SemanticItem170(root);
		break;
	case 171:
		std_analisys=SemanticItem171(root);
		break;
	case 172:
		std_analisys=SemanticItem172(root);
		break;
	case 173:
		std_analisys=SemanticItem173(root);
		break;
	case 174:
		std_analisys=SemanticItem174(root);
		break;
	case 175:
		std_analisys=SemanticItem175(root);
		break;
	case 176:
		std_analisys=SemanticItem176(root);
		break;
	case 177:
		std_analisys=SemanticItem177(root);
		break;
	case 178:
		std_analisys=SemanticItem178(root);
		break;
	case 179:
		std_analisys=SemanticItem179(root);
		break;
	case 180:
		std_analisys=SemanticItem180(root);
		break;
	case 181:
		std_analisys=SemanticItem181(root);
		break;
	case 182:
		std_analisys=SemanticItem182(root);
		break;
	case 183:
		std_analisys=SemanticItem183(root);
		break;
	case 184:
		std_analisys=SemanticItem184(root);
		break;
	case 185:
		std_analisys=SemanticItem185(root);
		break;
	case 186:
		std_analisys=SemanticItem186(root);
		break;
	case 187:
		std_analisys=SemanticItem187(root);
		break;
	case 188:
		std_analisys=SemanticItem188(root);
		break;
	case 189:
		std_analisys=SemanticItem189(root);
		break;
	case 190:
		std_analisys=SemanticItem190(root);
		break;
	case 191:
		std_analisys=SemanticItem191(root);
		break;
	case 192:
		std_analisys=SemanticItem192(root);
		break;
	case 193:
		std_analisys=SemanticItem193(root);
		break;
	case 194:
		std_analisys=SemanticItem194(root);
		break;
	case 195:
		std_analisys=SemanticItem195(root);
		break;
	case 196:
		std_analisys=SemanticItem196(root);
		break;
	case 197:
		std_analisys=SemanticItem197(root);
		break;
	case 198:
		std_analisys=SemanticItem198(root);
		break;
	case 199:
		std_analisys=SemanticItem199(root);
		break;
	case 200:
		std_analisys=SemanticItem200(root);
		break;
	case 201:
		std_analisys=SemanticItem201(root);
		break;
	case 202:
		std_analisys=SemanticItem202(root);
		break;
	case 203:
		std_analisys=SemanticItem203(root);
		break;
	case 204:
		std_analisys=SemanticItem204(root);
		break;
	case 205:
		std_analisys=SemanticItem205(root);
		break;
	case 206:
		std_analisys=SemanticItem206(root);
		break;
	case 207:
		std_analisys=SemanticItem207(root);
		break;
	case 208:
		std_analisys=SemanticItem208(root);
		break;
	case 209:
		std_analisys=SemanticItem209(root);
		break;
	case 210:
		std_analisys=SemanticItem210(root);
		break;
	case 211:
		std_analisys=SemanticItem211(root);
		break;
	case 212:
		std_analisys=SemanticItem212(root);
		break;
	case 213:
		std_analisys=SemanticItem213(root);
		break;
	case 214:
		std_analisys=SemanticItem214(root);
		break;
	case 215:
		std_analisys=SemanticItem215(root);
		break;
	case 216:
		std_analisys=SemanticItem216(root);
		break;
	case 217:
		std_analisys=SemanticItem217(root);
		break;
	case 218:
		std_analisys=SemanticItem218(root);
		break;
	case 219:
		std_analisys=SemanticItem219(root);
		break;
	case 220:
		std_analisys=SemanticItem220(root);
		break;
	case 221:
		std_analisys=SemanticItem221(root);
		break;
	case 222:
		std_analisys=SemanticItem222(root);
		break;
	case 223:
		std_analisys=SemanticItem223(root);
		break;
	case 224:
		std_analisys=SemanticItem224(root);
		break;
	case 225:
		std_analisys=SemanticItem225(root);
		break;
	case 226:
		std_analisys=SemanticItem226(root);
		break;
	case 227:
		std_analisys=SemanticItem227(root);
		break;
	case 228:
		std_analisys=SemanticItem228(root);
		break;
	case 229:
		std_analisys=SemanticItem229(root);
		break;
	case 230:
		std_analisys=SemanticItem230(root);
		break;
	case 231:
		std_analisys=SemanticItem231(root);
		break;
	case 232:
		std_analisys=SemanticItem232(root);
		break;
	case 233:
		std_analisys=SemanticItem233(root);
		break;
	case 234:
		std_analisys=SemanticItem234(root);
		break;
	case 235:
		std_analisys=SemanticItem235(root);
		break;
	case 236:
		std_analisys=SemanticItem236(root);
		break;
	case 237:
		std_analisys=SemanticItem237(root);
		break;
	case 238:
		std_analisys=SemanticItem238(root);
		break;
	case 239:
		std_analisys=SemanticItem239(root);
		break;
	case 240:
		std_analisys=SemanticItem240(root);
		break;
	case 241:
		std_analisys=SemanticItem241(root);
		break;
	case 242:
		std_analisys=SemanticItem242(root);
		break;
	case 243:
		std_analisys=SemanticItem243(root);
		break;
	case 244:
		std_analisys=SemanticItem244(root);
		break;
	case 245:
		std_analisys=SemanticItem245(root);
		break;
	case 246:
		std_analisys=SemanticItem246(root);
		break;
	case 247:
		std_analisys=SemanticItem247(root);
		break;
	case 248:
		std_analisys=SemanticItem248(root);
		break;
	case 249:
		std_analisys=SemanticItem249(root);
		break;
	case 250:
		std_analisys=SemanticItem250(root);
		break;
	case 251:
		std_analisys=SemanticItem251(root);
		break;
	case 252:
		std_analisys=SemanticItem252(root);
		break;
	case 253:
		std_analisys=SemanticItem253(root);
		break;
	case 254:
		std_analisys=SemanticItem254(root);
		break;
	case 255:
		std_analisys=SemanticItem255(root);
		break;
	case 256:
		std_analisys=SemanticItem256(root);
		break;
	case 257:
		std_analisys=SemanticItem257(root);
		break;
	case 258:
		std_analisys=SemanticItem258(root);
		break;
	case 259:
		std_analisys=SemanticItem259(root);
		break;
	case 260:
		std_analisys=SemanticItem260(root);
		break;
	case 261:
		std_analisys=SemanticItem261(root);
		break;
	case 262:
		std_analisys=SemanticItem262(root);
		break;
	case 263:
		std_analisys=SemanticItem263(root);
		break;
	case 264:
		std_analisys=SemanticItem264(root);
		break;
	case 265:
		std_analisys=SemanticItem265(root);
		break;
	case 266:
		std_analisys=SemanticItem266(root);
		break;
	case 267:
		std_analisys=SemanticItem267(root);
		break;
	case 268:
		std_analisys=SemanticItem268(root);
		break;
	case 269:
		std_analisys=SemanticItem269(root);
		break;
	case 270:
		std_analisys=SemanticItem270(root);
		break;
	case 271:
		std_analisys=SemanticItem271(root);
		break;
	case 272:
		std_analisys=SemanticItem272(root);
		break;
	case 273:
		std_analisys=SemanticItem273(root);
		break;
	case 274:
		std_analisys=SemanticItem274(root);
		break;
	case 275:
		std_analisys=SemanticItem275(root);
		break;
	case 276:
		std_analisys=SemanticItem276(root);
		break;
	case 277:
		std_analisys=SemanticItem277(root);
		break;
	case 278:
		std_analisys=SemanticItem278(root);
		break;
	case 279:
		std_analisys=SemanticItem279(root);
		break;
	case 280:
		std_analisys=SemanticItem280(root);
		break;
	case 281:
		std_analisys=SemanticItem281(root);
		break;
	case 282:
		std_analisys=SemanticItem282(root);
		break;
	case 283:
		std_analisys=SemanticItem283(root);
		break;
	case 284:
		std_analisys=SemanticItem284(root);
		break;
	case 285:
		std_analisys=SemanticItem285(root);
		break;
	case 286:
		std_analisys=SemanticItem286(root);
		break;
	case 287:
		std_analisys=SemanticItem287(root);
		break;
	case 288:
		std_analisys=SemanticItem288(root);
		break;
	case 289:
		std_analisys=SemanticItem289(root);
		break;
	case 290:
		std_analisys=SemanticItem290(root);
		break;
	case 291:
		std_analisys=SemanticItem291(root);
		break;
	case 292:
		std_analisys=SemanticItem292(root);
		break;
	case 293:
		std_analisys=SemanticItem293(root);
		break;
	case 294:
		std_analisys=SemanticItem294(root);
		break;
	case 295:
		std_analisys=SemanticItem295(root);
		break;
	case 296:
		std_analisys=SemanticItem296(root);
		break;
	case 297:
		std_analisys=SemanticItem297(root);
		break;
	case 298:
		std_analisys=SemanticItem298(root);
		break;
	case 299:
		std_analisys=SemanticItem299(root);
		break;
	case 300:
		std_analisys=SemanticItem300(root);
		break;
	case 301:
		std_analisys=SemanticItem301(root);
		break;
	case 302:
		std_analisys=SemanticItem302(root);
		break;
	case 303:
		std_analisys=SemanticItem303(root);
		break;
	case 304:
		std_analisys=SemanticItem304(root);
		break;
	case 305:
		std_analisys=SemanticItem305(root);
		break;
	case 306:
		std_analisys=SemanticItem306(root);
		break;
	case 307:
		std_analisys=SemanticItem307(root);
		break;
	case 308:
		std_analisys=SemanticItem308(root);
		break;
	case 309:
		std_analisys=SemanticItem309(root);
		break;
	case 310:
		std_analisys=SemanticItem310(root);
		break;
	case 311:
		std_analisys=SemanticItem311(root);
		break;
	case 312:
		std_analisys=SemanticItem312(root);
		break;
	case 313:
		std_analisys=SemanticItem313(root);
		break;
	case 314:
		std_analisys=SemanticItem314(root);
		break;
	case 315:
		std_analisys=SemanticItem315(root);
		break;
	case 316:
		std_analisys=SemanticItem316(root);
		break;
	case 317:
		std_analisys=SemanticItem317(root);
		break;
	case 318:
		std_analisys=SemanticItem318(root);
		break;
	case 319:
		std_analisys=SemanticItem319(root);
		break;
	case 320:
		std_analisys=SemanticItem320(root);
		break;
	case 321:
		std_analisys=SemanticItem321(root);
		break;
	case 322:
		std_analisys=SemanticItem322(root);
		break;
	case 323:
		std_analisys=SemanticItem323(root);
		break;
	case 324:
		std_analisys=SemanticItem324(root);
		break;
	case 325:
		std_analisys=SemanticItem325(root);
		break;
	case 326:
		std_analisys=SemanticItem326(root);
		break;
	case 327:
		std_analisys=SemanticItem327(root);
		break;
	case 328:
		std_analisys=SemanticItem328(root);
		break;
	}
	if (std_analisys)
	{
		std::vector<CPeterCompiler::CTree*>::iterator b,e,i;
		b=root->m_vComponents.begin();
		e=root->m_vComponents.end();
		for(i=b;i!=e;i++) Analisys(*i);
	}
}

void CJavaC16XCompiler::Translate(std::ofstream &out,CTree*) throw(CPeterCompiler::CSemanticException)
{
}	

void CJavaC16XCompiler::Compile(std::ofstream &out,CTree* root) throw(CPeterCompiler::CSemanticException)
{
	m_ptTarget->BeginCompile(out);
	CompileSub(root);
	m_ptTarget->EndCompile();
}

void CJavaC16XCompiler::Clear()
{
	DeleteAll();
}

void CJavaC16XCompiler::PreTranslate()
{
}

void CJavaC16XCompiler::PreCompile()
{
}

void CJavaC16XCompiler::CompileSub(CTree* root) throw(CPeterCompiler::CSemanticException)
{
	bool std_compile=true;
	switch(root->m_iRule)
	{
	case 1:
		std_compile=CompileItem1(root);
		break;
	case 2:
		std_compile=CompileItem2(root);
		break;
	case 3:
		std_compile=CompileItem3(root);
		break;
	case 4:
		std_compile=CompileItem4(root);
		break;
	case 5:
		std_compile=CompileItem5(root);
		break;
	case 6:
		std_compile=CompileItem6(root);
		break;
	case 7:
		std_compile=CompileItem7(root);
		break;
	case 8:
		std_compile=CompileItem8(root);
		break;
	case 9:
		std_compile=CompileItem9(root);
		break;
	case 10:
		std_compile=CompileItem10(root);
		break;
	case 11:
		std_compile=CompileItem11(root);
		break;
	case 12:
		std_compile=CompileItem12(root);
		break;
	case 13:
		std_compile=CompileItem13(root);
		break;
	case 14:
		std_compile=CompileItem14(root);
		break;
	case 15:
		std_compile=CompileItem15(root);
		break;
	case 16:
		std_compile=CompileItem16(root);
		break;
	case 17:
		std_compile=CompileItem17(root);
		break;
	case 18:
		std_compile=CompileItem18(root);
		break;
	case 19:
		std_compile=CompileItem19(root);
		break;
	case 20:
		std_compile=CompileItem20(root);
		break;
	case 21:
		std_compile=CompileItem21(root);
		break;
	case 22:
		std_compile=CompileItem22(root);
		break;
	case 23:
		std_compile=CompileItem23(root);
		break;
	case 24:
		std_compile=CompileItem24(root);
		break;
	case 25:
		std_compile=CompileItem25(root);
		break;
	case 26:
		std_compile=CompileItem26(root);
		break;
	case 27:
		std_compile=CompileItem27(root);
		break;
	case 28:
		std_compile=CompileItem28(root);
		break;
	case 29:
		std_compile=CompileItem29(root);
		break;
	case 30:
		std_compile=CompileItem30(root);
		break;
	case 31:
		std_compile=CompileItem31(root);
		break;
	case 32:
		std_compile=CompileItem32(root);
		break;
	case 33:
		std_compile=CompileItem33(root);
		break;
	case 34:
		std_compile=CompileItem34(root);
		break;
	case 35:
		std_compile=CompileItem35(root);
		break;
	case 36:
		std_compile=CompileItem36(root);
		break;
	case 37:
		std_compile=CompileItem37(root);
		break;
	case 38:
		std_compile=CompileItem38(root);
		break;
	case 39:
		std_compile=CompileItem39(root);
		break;
	case 40:
		std_compile=CompileItem40(root);
		break;
	case 41:
		std_compile=CompileItem41(root);
		break;
	case 42:
		std_compile=CompileItem42(root);
		break;
	case 43:
		std_compile=CompileItem43(root);
		break;
	case 44:
		std_compile=CompileItem44(root);
		break;
	case 45:
		std_compile=CompileItem45(root);
		break;
	case 46:
		std_compile=CompileItem46(root);
		break;
	case 47:
		std_compile=CompileItem47(root);
		break;
	case 48:
		std_compile=CompileItem48(root);
		break;
	case 49:
		std_compile=CompileItem49(root);
		break;
	case 50:
		std_compile=CompileItem50(root);
		break;
	case 51:
		std_compile=CompileItem51(root);
		break;
	case 52:
		std_compile=CompileItem52(root);
		break;
	case 53:
		std_compile=CompileItem53(root);
		break;
	case 54:
		std_compile=CompileItem54(root);
		break;
	case 55:
		std_compile=CompileItem55(root);
		break;
	case 56:
		std_compile=CompileItem56(root);
		break;
	case 57:
		std_compile=CompileItem57(root);
		break;
	case 58:
		std_compile=CompileItem58(root);
		break;
	case 59:
		std_compile=CompileItem59(root);
		break;
	case 60:
		std_compile=CompileItem60(root);
		break;
	case 61:
		std_compile=CompileItem61(root);
		break;
	case 62:
		std_compile=CompileItem62(root);
		break;
	case 63:
		std_compile=CompileItem63(root);
		break;
	case 64:
		std_compile=CompileItem64(root);
		break;
	case 65:
		std_compile=CompileItem65(root);
		break;
	case 66:
		std_compile=CompileItem66(root);
		break;
	case 67:
		std_compile=CompileItem67(root);
		break;
	case 68:
		std_compile=CompileItem68(root);
		break;
	case 69:
		std_compile=CompileItem69(root);
		break;
	case 70:
		std_compile=CompileItem70(root);
		break;
	case 71:
		std_compile=CompileItem71(root);
		break;
	case 72:
		std_compile=CompileItem72(root);
		break;
	case 73:
		std_compile=CompileItem73(root);
		break;
	case 74:
		std_compile=CompileItem74(root);
		break;
	case 75:
		std_compile=CompileItem75(root);
		break;
	case 76:
		std_compile=CompileItem76(root);
		break;
	case 77:
		std_compile=CompileItem77(root);
		break;
	case 78:
		std_compile=CompileItem78(root);
		break;
	case 79:
		std_compile=CompileItem79(root);
		break;
	case 80:
		std_compile=CompileItem80(root);
		break;
	case 81:
		std_compile=CompileItem81(root);
		break;
	case 82:
		std_compile=CompileItem82(root);
		break;
	case 83:
		std_compile=CompileItem83(root);
		break;
	case 84:
		std_compile=CompileItem84(root);
		break;
	case 85:
		std_compile=CompileItem85(root);
		break;
	case 86:
		std_compile=CompileItem86(root);
		break;
	case 87:
		std_compile=CompileItem87(root);
		break;
	case 88:
		std_compile=CompileItem88(root);
		break;
	case 89:
		std_compile=CompileItem89(root);
		break;
	case 90:
		std_compile=CompileItem90(root);
		break;
	case 91:
		std_compile=CompileItem91(root);
		break;
	case 92:
		std_compile=CompileItem92(root);
		break;
	case 93:
		std_compile=CompileItem93(root);
		break;
	case 94:
		std_compile=CompileItem94(root);
		break;
	case 95:
		std_compile=CompileItem95(root);
		break;
	case 96:
		std_compile=CompileItem96(root);
		break;
	case 97:
		std_compile=CompileItem97(root);
		break;
	case 98:
		std_compile=CompileItem98(root);
		break;
	case 99:
		std_compile=CompileItem99(root);
		break;
	case 100:
		std_compile=CompileItem100(root);
		break;
	case 101:
		std_compile=CompileItem101(root);
		break;
	case 102:
		std_compile=CompileItem102(root);
		break;
	case 103:
		std_compile=CompileItem103(root);
		break;
	case 104:
		std_compile=CompileItem104(root);
		break;
	case 105:
		std_compile=CompileItem105(root);
		break;
	case 106:
		std_compile=CompileItem106(root);
		break;
	case 107:
		std_compile=CompileItem107(root);
		break;
	case 108:
		std_compile=CompileItem108(root);
		break;
	case 109:
		std_compile=CompileItem109(root);
		break;
	case 110:
		std_compile=CompileItem110(root);
		break;
	case 111:
		std_compile=CompileItem111(root);
		break;
	case 112:
		std_compile=CompileItem112(root);
		break;
	case 113:
		std_compile=CompileItem113(root);
		break;
	case 114:
		std_compile=CompileItem114(root);
		break;
	case 115:
		std_compile=CompileItem115(root);
		break;
	case 116:
		std_compile=CompileItem116(root);
		break;
	case 117:
		std_compile=CompileItem117(root);
		break;
	case 118:
		std_compile=CompileItem118(root);
		break;
	case 119:
		std_compile=CompileItem119(root);
		break;
	case 120:
		std_compile=CompileItem120(root);
		break;
	case 121:
		std_compile=CompileItem121(root);
		break;
	case 122:
		std_compile=CompileItem122(root);
		break;
	case 123:
		std_compile=CompileItem123(root);
		break;
	case 124:
		std_compile=CompileItem124(root);
		break;
	case 125:
		std_compile=CompileItem125(root);
		break;
	case 126:
		std_compile=CompileItem126(root);
		break;
	case 127:
		std_compile=CompileItem127(root);
		break;
	case 128:
		std_compile=CompileItem128(root);
		break;
	case 129:
		std_compile=CompileItem129(root);
		break;
	case 130:
		std_compile=CompileItem130(root);
		break;
	case 131:
		std_compile=CompileItem131(root);
		break;
	case 132:
		std_compile=CompileItem132(root);
		break;
	case 133:
		std_compile=CompileItem133(root);
		break;
	case 134:
		std_compile=CompileItem134(root);
		break;
	case 135:
		std_compile=CompileItem135(root);
		break;
	case 136:
		std_compile=CompileItem136(root);
		break;
	case 137:
		std_compile=CompileItem137(root);
		break;
	case 138:
		std_compile=CompileItem138(root);
		break;
	case 139:
		std_compile=CompileItem139(root);
		break;
	case 140:
		std_compile=CompileItem140(root);
		break;
	case 141:
		std_compile=CompileItem141(root);
		break;
	case 142:
		std_compile=CompileItem142(root);
		break;
	case 143:
		std_compile=CompileItem143(root);
		break;
	case 144:
		std_compile=CompileItem144(root);
		break;
	case 145:
		std_compile=CompileItem145(root);
		break;
	case 146:
		std_compile=CompileItem146(root);
		break;
	case 147:
		std_compile=CompileItem147(root);
		break;
	case 148:
		std_compile=CompileItem148(root);
		break;
	case 149:
		std_compile=CompileItem149(root);
		break;
	case 150:
		std_compile=CompileItem150(root);
		break;
	case 151:
		std_compile=CompileItem151(root);
		break;
	case 152:
		std_compile=CompileItem152(root);
		break;
	case 153:
		std_compile=CompileItem153(root);
		break;
	case 154:
		std_compile=CompileItem154(root);
		break;
	case 155:
		std_compile=CompileItem155(root);
		break;
	case 156:
		std_compile=CompileItem156(root);
		break;
	case 157:
		std_compile=CompileItem157(root);
		break;
	case 158:
		std_compile=CompileItem158(root);
		break;
	case 159:
		std_compile=CompileItem159(root);
		break;
	case 160:
		std_compile=CompileItem160(root);
		break;
	case 161:
		std_compile=CompileItem161(root);
		break;
	case 162:
		std_compile=CompileItem162(root);
		break;
	case 163:
		std_compile=CompileItem163(root);
		break;
	case 164:
		std_compile=CompileItem164(root);
		break;
	case 165:
		std_compile=CompileItem165(root);
		break;
	case 166:
		std_compile=CompileItem166(root);
		break;
	case 167:
		std_compile=CompileItem167(root);
		break;
	case 168:
		std_compile=CompileItem168(root);
		break;
	case 169:
		std_compile=CompileItem169(root);
		break;
	case 170:
		std_compile=CompileItem170(root);
		break;
	case 171:
		std_compile=CompileItem171(root);
		break;
	case 172:
		std_compile=CompileItem172(root);
		break;
	case 173:
		std_compile=CompileItem173(root);
		break;
	case 174:
		std_compile=CompileItem174(root);
		break;
	case 175:
		std_compile=CompileItem175(root);
		break;
	case 176:
		std_compile=CompileItem176(root);
		break;
	case 177:
		std_compile=CompileItem177(root);
		break;
	case 178:
		std_compile=CompileItem178(root);
		break;
	case 179:
		std_compile=CompileItem179(root);
		break;
	case 180:
		std_compile=CompileItem180(root);
		break;
	case 181:
		std_compile=CompileItem181(root);
		break;
	case 182:
		std_compile=CompileItem182(root);
		break;
	case 183:
		std_compile=CompileItem183(root);
		break;
	case 184:
		std_compile=CompileItem184(root);
		break;
	case 185:
		std_compile=CompileItem185(root);
		break;
	case 186:
		std_compile=CompileItem186(root);
		break;
	case 187:
		std_compile=CompileItem187(root);
		break;
	case 188:
		std_compile=CompileItem188(root);
		break;
	case 189:
		std_compile=CompileItem189(root);
		break;
	case 190:
		std_compile=CompileItem190(root);
		break;
	case 191:
		std_compile=CompileItem191(root);
		break;
	case 192:
		std_compile=CompileItem192(root);
		break;
	case 193:
		std_compile=CompileItem193(root);
		break;
	case 194:
		std_compile=CompileItem194(root);
		break;
	case 195:
		std_compile=CompileItem195(root);
		break;
	case 196:
		std_compile=CompileItem196(root);
		break;
	case 197:
		std_compile=CompileItem197(root);
		break;
	case 198:
		std_compile=CompileItem198(root);
		break;
	case 199:
		std_compile=CompileItem199(root);
		break;
	case 200:
		std_compile=CompileItem200(root);
		break;
	case 201:
		std_compile=CompileItem201(root);
		break;
	case 202:
		std_compile=CompileItem202(root);
		break;
	case 203:
		std_compile=CompileItem203(root);
		break;
	case 204:
		std_compile=CompileItem204(root);
		break;
	case 205:
		std_compile=CompileItem205(root);
		break;
	case 206:
		std_compile=CompileItem206(root);
		break;
	case 207:
		std_compile=CompileItem207(root);
		break;
	case 208:
		std_compile=CompileItem208(root);
		break;
	case 209:
		std_compile=CompileItem209(root);
		break;
	case 210:
		std_compile=CompileItem210(root);
		break;
	case 211:
		std_compile=CompileItem211(root);
		break;
	case 212:
		std_compile=CompileItem212(root);
		break;
	case 213:
		std_compile=CompileItem213(root);
		break;
	case 214:
		std_compile=CompileItem214(root);
		break;
	case 215:
		std_compile=CompileItem215(root);
		break;
	case 216:
		std_compile=CompileItem216(root);
		break;
	case 217:
		std_compile=CompileItem217(root);
		break;
	case 218:
		std_compile=CompileItem218(root);
		break;
	case 219:
		std_compile=CompileItem219(root);
		break;
	case 220:
		std_compile=CompileItem220(root);
		break;
	case 221:
		std_compile=CompileItem221(root);
		break;
	case 222:
		std_compile=CompileItem222(root);
		break;
	case 223:
		std_compile=CompileItem223(root);
		break;
	case 224:
		std_compile=CompileItem224(root);
		break;
	case 225:
		std_compile=CompileItem225(root);
		break;
	case 226:
		std_compile=CompileItem226(root);
		break;
	case 227:
		std_compile=CompileItem227(root);
		break;
	case 228:
		std_compile=CompileItem228(root);
		break;
	case 229:
		std_compile=CompileItem229(root);
		break;
	case 230:
		std_compile=CompileItem230(root);
		break;
	case 231:
		std_compile=CompileItem231(root);
		break;
	case 232:
		std_compile=CompileItem232(root);
		break;
	case 233:
		std_compile=CompileItem233(root);
		break;
	case 234:
		std_compile=CompileItem234(root);
		break;
	case 235:
		std_compile=CompileItem235(root);
		break;
	case 236:
		std_compile=CompileItem236(root);
		break;
	case 237:
		std_compile=CompileItem237(root);
		break;
	case 238:
		std_compile=CompileItem238(root);
		break;
	case 239:
		std_compile=CompileItem239(root);
		break;
	case 240:
		std_compile=CompileItem240(root);
		break;
	case 241:
		std_compile=CompileItem241(root);
		break;
	case 242:
		std_compile=CompileItem242(root);
		break;
	case 243:
		std_compile=CompileItem243(root);
		break;
	case 244:
		std_compile=CompileItem244(root);
		break;
	case 245:
		std_compile=CompileItem245(root);
		break;
	case 246:
		std_compile=CompileItem246(root);
		break;
	case 247:
		std_compile=CompileItem247(root);
		break;
	case 248:
		std_compile=CompileItem248(root);
		break;
	case 249:
		std_compile=CompileItem249(root);
		break;
	case 250:
		std_compile=CompileItem250(root);
		break;
	case 251:
		std_compile=CompileItem251(root);
		break;
	case 252:
		std_compile=CompileItem252(root);
		break;
	case 253:
		std_compile=CompileItem253(root);
		break;
	case 254:
		std_compile=CompileItem254(root);
		break;
	case 255:
		std_compile=CompileItem255(root);
		break;
	case 256:
		std_compile=CompileItem256(root);
		break;
	case 257:
		std_compile=CompileItem257(root);
		break;
	case 258:
		std_compile=CompileItem258(root);
		break;
	case 259:
		std_compile=CompileItem259(root);
		break;
	case 260:
		std_compile=CompileItem260(root);
		break;
	case 261:
		std_compile=CompileItem261(root);
		break;
	case 262:
		std_compile=CompileItem262(root);
		break;
	case 263:
		std_compile=CompileItem263(root);
		break;
	case 264:
		std_compile=CompileItem264(root);
		break;
	case 265:
		std_compile=CompileItem265(root);
		break;
	case 266:
		std_compile=CompileItem266(root);
		break;
	case 267:
		std_compile=CompileItem267(root);
		break;
	case 268:
		std_compile=CompileItem268(root);
		break;
	case 269:
		std_compile=CompileItem269(root);
		break;
	case 270:
		std_compile=CompileItem270(root);
		break;
	case 271:
		std_compile=CompileItem271(root);
		break;
	case 272:
		std_compile=CompileItem272(root);
		break;
	case 273:
		std_compile=CompileItem273(root);
		break;
	case 274:
		std_compile=CompileItem274(root);
		break;
	case 275:
		std_compile=CompileItem275(root);
		break;
	case 276:
		std_compile=CompileItem276(root);
		break;
	case 277:
		std_compile=CompileItem277(root);
		break;
	case 278:
		std_compile=CompileItem278(root);
		break;
	case 279:
		std_compile=CompileItem279(root);
		break;
	case 280:
		std_compile=CompileItem280(root);
		break;
	case 281:
		std_compile=CompileItem281(root);
		break;
	case 282:
		std_compile=CompileItem282(root);
		break;
	case 283:
		std_compile=CompileItem283(root);
		break;
	case 284:
		std_compile=CompileItem284(root);
		break;
	case 285:
		std_compile=CompileItem285(root);
		break;
	case 286:
		std_compile=CompileItem286(root);
		break;
	case 287:
		std_compile=CompileItem287(root);
		break;
	case 288:
		std_compile=CompileItem288(root);
		break;
	case 289:
		std_compile=CompileItem289(root);
		break;
	case 290:
		std_compile=CompileItem290(root);
		break;
	case 291:
		std_compile=CompileItem291(root);
		break;
	case 292:
		std_compile=CompileItem292(root);
		break;
	case 293:
		std_compile=CompileItem293(root);
		break;
	case 294:
		std_compile=CompileItem294(root);
		break;
	case 295:
		std_compile=CompileItem295(root);
		break;
	case 296:
		std_compile=CompileItem296(root);
		break;
	case 297:
		std_compile=CompileItem297(root);
		break;
	case 298:
		std_compile=CompileItem298(root);
		break;
	case 299:
		std_compile=CompileItem299(root);
		break;
	case 300:
		std_compile=CompileItem300(root);
		break;
	case 301:
		std_compile=CompileItem301(root);
		break;
	case 302:
		std_compile=CompileItem302(root);
		break;
	case 303:
		std_compile=CompileItem303(root);
		break;
	case 304:
		std_compile=CompileItem304(root);
		break;
	case 305:
		std_compile=CompileItem305(root);
		break;
	case 306:
		std_compile=CompileItem306(root);
		break;
	case 307:
		std_compile=CompileItem307(root);
		break;
	case 308:
		std_compile=CompileItem308(root);
		break;
	case 309:
		std_compile=CompileItem309(root);
		break;
	case 310:
		std_compile=CompileItem310(root);
		break;
	case 311:
		std_compile=CompileItem311(root);
		break;
	case 312:
		std_compile=CompileItem312(root);
		break;
	case 313:
		std_compile=CompileItem313(root);
		break;
	case 314:
		std_compile=CompileItem314(root);
		break;
	case 315:
		std_compile=CompileItem315(root);
		break;
	case 316:
		std_compile=CompileItem316(root);
		break;
	case 317:
		std_compile=CompileItem317(root);
		break;
	case 318:
		std_compile=CompileItem318(root);
		break;
	case 319:
		std_compile=CompileItem319(root);
		break;
	case 320:
		std_compile=CompileItem320(root);
		break;
	case 321:
		std_compile=CompileItem321(root);
		break;
	case 322:
		std_compile=CompileItem322(root);
		break;
	case 323:
		std_compile=CompileItem323(root);
		break;
	case 324:
		std_compile=CompileItem324(root);
		break;
	case 325:
		std_compile=CompileItem325(root);
		break;
	case 326:
		std_compile=CompileItem326(root);
		break;
	case 327:
		std_compile=CompileItem327(root);
		break;
	case 328:
		std_compile=CompileItem328(root);
		break;
	}
	if (std_compile)
	{
		std::vector<CPeterCompiler::CTree*>::iterator b,e,i;
		b=root->m_vComponents.begin();
		e=root->m_vComponents.end();
		for(i=b;i!=e;i++) CompileSub(*i);
	}
}

/////////////////////////////////////////////
// Rule semantic analisys
/////////////////////////////////////////////

#include "RuleSemantic.h"

/////////////////////////////////////////////
// Rule compilations
/////////////////////////////////////////////

#include "RuleCompilations.h"

/////////////////////////////////////////////
// GetTreeComponents
/////////////////////////////////////////////

std::string CJavaC16XCompiler::GetQualifiedIdentifiers(CTree* root)
{
	std::string result="";
	if (!root->m_vComponents.empty())
	{
		result=result+root->m_vComponents[0]->m_sLexem_value+root->m_vComponents[1]->m_sLexem_value;	
		result=result+GetQualifiedIdentifiers(root->m_vComponents[2]);
	}
	return result;
}

std::string CJavaC16XCompiler::GetQualifiedIdentifier(CTree* root)
{
	CTree* sub=root->m_vComponents[0];
	std::string result=sub->m_sLexem_value;
	return result+GetQualifiedIdentifiers(root->m_vComponents[1]);
}

int CJavaC16XCompiler::GetMaxMethodId()
{
	int nmax=0;
	std::set<CClass,Class_less>::iterator b,e,i;
	b=m_stClasses.begin();
	e=m_stClasses.end();
	for(i=b;i!=e;i++)
	{
		int cmax=(*i).GetMaxMethodId();
		if (cmax>nmax) nmax=cmax;
	}
	b=m_stInterfaces.begin();
	e=m_stInterfaces.end();
	for(i=b;i!=e;i++)
	{
		int cmax=(*i).GetMaxMethodId();
		if (cmax>nmax) nmax=cmax;
	}
	return nmax;
}

int CJavaC16XCompiler::GetMaxStaticId()
{
	int nmax=0;
	std::set<CClass,Class_less>::iterator b,e,i;
	b=m_stClasses.begin();
	e=m_stClasses.end();
	for(i=b;i!=e;i++)
	{
		int cmax=(*i).GetMaxStaticId();
		if (cmax>nmax) nmax=cmax;
	}
	b=m_stInterfaces.begin();
	e=m_stInterfaces.end();
	for(i=b;i!=e;i++)
	{
		int cmax=(*i).GetMaxStaticId();
		if (cmax>nmax) nmax=cmax;
	}
	return nmax;
}

int CJavaC16XCompiler::GetMaxHeapId()
{
	int nmax=0;
	std::set<CClass,Class_less>::iterator b,e,i;
	b=m_stClasses.begin();
	e=m_stClasses.end();
	for(i=b;i!=e;i++)
	{
		int cmax=(*i).GetMaxHeapId();
		if (cmax>nmax) nmax=cmax;
	}
	b=m_stInterfaces.begin();
	e=m_stInterfaces.end();
	for(i=b;i!=e;i++)
	{
		int cmax=(*i).GetMaxHeapId();
		if (cmax>nmax) nmax=cmax;
	}
	return nmax;
}

__JAVA_C16X_END