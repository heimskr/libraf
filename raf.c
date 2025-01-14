#include <string.h>
#include <unistd.h>

#include "raf.h"

// made with https://dom111.github.io/image-to-ansi/
const char *raf_true_color_1
	= "\x1b[48;2;0;0;0m          "
	  "\x1b[38;2;90;60;30m▄\x1b[48;2;0;0;0m\x1b[38;2;113;74;12m▄\x1b[48;2;187;150;86m\x1b[38;2;147;"
	  "86;31m▄\x1b[48;2;199;150;71m\x1b[38;2;164;99;41m▄\x1b[48;2;150;85;31m\x1b[38;2;179;113;"
	  "52m▄\x1b[48;2;85;85;0m\x1b[38;2;129;84;29m▄\x1b[48;2;0;0;0m\x1b[38;2;139;123;82m▄\x1b[48;2;"
	  "0;0;0m       \x1b[0m\n"
	  "\x1b[48;2;0;0;0m        "
	  "\x1b[38;2;145;100;36m▄\x1b[48;2;89;76;25m\x1b[38;2;194;132;52m▄\x1b[48;2;230;172;83m\x1b[38;"
	  "2;219;151;68m▄\x1b[48;2;233;152;61m\x1b[38;2;236;156;66m▄\x1b[48;2;248;160;66m\x1b[38;2;240;"
	  "152;61m▄\x1b[48;2;247;162;72m\x1b[38;2;240;154;58m▄\x1b[48;2;228;144;61m\x1b[38;2;230;149;"
	  "65m▄\x1b[48;2;218;141;60m\x1b[38;2;196;116;48m▄\x1b[48;2;167;107;42m\x1b[38;2;194;121;"
	  "54m▄\x1b[48;2;0;0;0m\x1b[38;2;175;105;41m▄\x1b[48;2;0;0;0m\x1b[38;2;241;129;33m▄\x1b[48;2;0;"
	  "0;0m     \x1b[0m\n"
	  "\x1b[48;2;0;0;0m     "
	  "\x1b[38;2;135;99;54m▄\x1b[48;2;150;99;53m\x1b[38;2;193;121;57m▄\x1b[48;2;178;129;57m\x1b[38;"
	  "2;206;127;50m▄\x1b[48;2;142;87;43m\x1b[38;2;163;105;43m▄\x1b[48;2;164;102;37m\x1b[38;2;184;"
	  "140;82m▄\x1b[48;2;137;84;33m\x1b[38;2;173;128;85m▄\x1b[48;2;165;101;38m\x1b[38;2;157;104;"
	  "53m▄\x1b[48;2;226;139;65m\x1b[38;2;209;127;52m▄\x1b[48;2;209;132;63m\x1b[38;2;158;87;"
	  "27m▄\x1b[48;2;121;66;20m\x1b[38;2;133;74;32m▄\x1b[48;2;166;130;94m\x1b[38;2;192;135;"
	  "78m▄\x1b[48;2;150;88;28m\x1b[38;2;206;131;55m▄\x1b[48;2;192;122;55m\x1b[38;2;222;138;"
	  "60m▄\x1b[48;2;193;129;49m\x1b[38;2;183;112;41m▄\x1b[48;2;182;120;48m\x1b[38;2;127;84;"
	  "35m▄\x1b[48;2;0;0;0m    \x1b[0m\n"
	  "\x1b[48;2;0;0;0m  "
	  "\x1b[38;2;132;113;89m▄\x1b[48;2;170;170;170m\x1b[38;2;127;77;25m▄\x1b[48;2;137;89;41m\x1b["
	  "38;2;175;109;39m▄\x1b[48;2;180;116;47m\x1b[38;2;206;129;54m▄\x1b[48;2;220;142;59m\x1b[38;2;"
	  "221;144;65m▄\x1b[48;2;223;143;58m\x1b[38;2;221;145;64m▄\x1b[48;2;204;133;58m\x1b[38;2;210;"
	  "141;63m▄\x1b[48;2;160;101;36m\x1b[38;2;201;131;53m▄\x1b[48;2;155;101;40m\x1b[38;2;187;117;"
	  "46m▄\x1b[48;2;172;105;39m\x1b[38;2;237;157;67m▄\x1b[48;2;230;149;69m\x1b[38;2;247;155;"
	  "63m▄\x1b[48;2;181;106;31m\x1b[38;2;210;122;45m▄\x1b[48;2;192;119;52m\x1b[38;2;213;135;"
	  "60m▄\x1b[48;2;207;132;61m\x1b[38;2;230;154;80m▄\x1b[48;2;232;151;72m\x1b[38;2;227;154;"
	  "75m▄\x1b[48;2;229;144;68m\x1b[38;2;211;138;62m▄\x1b[48;2;198;119;53m\x1b[38;2;196;121;"
	  "59m▄\x1b[48;2;155;96;47m\x1b[38;2;164;100;47m▄\x1b[48;2;61;30;9m\x1b[38;2;127;84;50m▄\x1b["
	  "48;2;0;0;0m\x1b[38;2;92;49;14m▄\x1b[48;2;0;0;0m  \x1b[0m\n"
	  "\x1b[48;2;0;0;0m\x1b[38;2;82;63;34m▄\x1b[48;2;138;109;87m\x1b[38;2;124;76;27m▄\x1b[48;2;142;"
	  "85;28m\x1b[38;2;162;97;36m▄\x1b[48;2;166;102;46m\x1b[38;2;176;112;43m▄\x1b[48;2;190;121;"
	  "51m\x1b[38;2;185;116;47m▄\x1b[48;2;201;126;55m\x1b[38;2;191;118;49m▄\x1b[48;2;204;131;"
	  "58m\x1b[38;2;193;121;47m▄\x1b[48;2;207;135;59m\x1b[38;2;195;125;53m▄\x1b[48;2;203;134;"
	  "55m\x1b[38;2;188;117;49m▄\x1b[48;2;190;121;44m\x1b[38;2;232;160;85m▄\x1b[48;2;234;158;"
	  "70m\x1b[38;2;242;151;61m▄\x1b[48;2;252;178;81m\x1b[38;2;251;186;85m▄\x1b[48;2;254;183;"
	  "83m\x1b[38;2;252;173;75m▄\x1b[48;2;230;138;65m\x1b[38;2;209;121;55m▄\x1b[48;2;193;114;"
	  "45m\x1b[38;2;179;103;44m▄\x1b[48;2;183;110;43m\x1b[38;2;186;114;50m▄\x1b[48;2;218;145;"
	  "75m\x1b[38;2;222;150;75m▄\x1b[48;2;206;133;62m\x1b[38;2;205;135;61m▄\x1b[48;2;195;122;"
	  "65m\x1b[38;2;186;117;56m▄\x1b[48;2;174;105;47m\x1b[38;2;174;106;48m▄\x1b[48;2;151;95;"
	  "49m\x1b[38;2;164;106;50m▄\x1b[48;2;95;57;22m\x1b[38;2;116;72;35m▄\x1b[48;2;103;72;43m\x1b["
	  "38;2;104;71;35m▄\x1b[48;2;0;0;0m\x1b[38;2;111;69;22m▄\x1b[0m\n";
const char *raf_true_color_2
	= "\x1b[48;2;127;84;34m\x1b[38;2;140;97;41m▄\x1b[48;2;160;103;42m\x1b[38;2;164;107;44m▄\x1b[48;"
	  "2;164;103;41m\x1b[38;2;167;107;45m▄\x1b[48;2;171;107;41m\x1b[38;2;171;111;47m▄\x1b[48;2;177;"
	  "111;43m\x1b[38;2;178;113;46m▄\x1b[48;2;182;113;43m\x1b[38;2;195;126;56m▄\x1b[48;2;187;116;"
	  "47m\x1b[38;2;203;135;65m▄\x1b[48;2;194;124;52m\x1b[38;2;204;135;60m▄\x1b[48;2;181;110;"
	  "43m\x1b[38;2;172;100;36m▄\x1b[48;2;77;33;8m\x1b[38;2;160;99;30m▄\x1b[48;2;142;71;22m\x1b[38;"
	  "2;178;102;46m▄\x1b[48;2;228;144;59m\x1b[38;2;201;123;43m▄\x1b[48;2;198;112;42m\x1b[38;2;227;"
	  "151;71m▄\x1b[48;2;89;36;1m\x1b[38;2;193;124;54m▄\x1b[48;2;148;94;48m\x1b[38;2;162;98;"
	  "33m▄\x1b[48;2;157;88;24m\x1b[38;2;186;119;55m▄\x1b[48;2;210;137;66m\x1b[38;2;190;119;"
	  "60m▄\x1b[48;2;201;129;56m\x1b[38;2;157;98;37m▄\x1b[48;2;188;118;58m\x1b[38;2;132;75;"
	  "28m▄\x1b[48;2;169;105;53m\x1b[38;2;104;56;19m▄\x1b[48;2;167;109;51m\x1b[38;2;138;88;"
	  "41m▄\x1b[48;2;135;86;44m\x1b[38;2;156;104;58m▄\x1b[48;2;110;75;40m\x1b[38;2;129;89;50m▄\x1b["
	  "48;2;122;80;42m\x1b[38;2;116;77;35m▄\x1b[0m\n"
	  "\x1b[48;2;157;105;48m\x1b[38;2;120;77;31m▄\x1b[48;2;155;103;48m\x1b[38;2;86;43;0m▄\x1b[48;2;"
	  "146;95;39m\x1b[38;2;106;62;16m▄\x1b[48;2;147;96;40m\x1b[38;2;104;61;16m▄\x1b[48;2;168;111;"
	  "43m\x1b[38;2;137;87;28m▄\x1b[48;2;176;112;45m\x1b[38;2;144;87;25m▄\x1b[48;2;192;128;61m\x1b["
	  "38;2;144;88;26m▄\x1b[48;2;188;122;53m\x1b[38;2;136;78;16m▄\x1b[48;2;178;114;45m\x1b[38;2;"
	  "156;95;32m▄\x1b[48;2;167;100;36m\x1b[38;2;149;83;17m▄\x1b[48;2;197;124;47m "
	  "\x1b[48;2;226;148;67m\x1b[38;2;221;142;61m▄\x1b[48;2;206;131;52m\x1b[38;2;197;121;42m▄\x1b["
	  "48;2;165;99;31m\x1b[38;2;207;138;65m▄\x1b[48;2;183;121;55m\x1b[38;2;216;150;77m▄\x1b[48;2;"
	  "133;73;11m\x1b[38;2;240;165;92m▄\x1b[48;2;141;82;23m\x1b[38;2;216;144;77m▄\x1b[48;2;176;113;"
	  "59m\x1b[38;2;189;118;61m▄\x1b[48;2;174;114;62m\x1b[38;2;130;73;25m▄\x1b[48;2;141;89;49m\x1b["
	  "38;2;162;106;62m▄\x1b[48;2;126;82;42m\x1b[38;2;140;92;48m▄\x1b[48;2;117;80;38m\x1b[38;2;106;"
	  "67;27m▄\x1b[48;2;117;78;39m\x1b[38;2;87;58;25m▄\x1b[48;2;113;77;37m\x1b[38;2;84;59;29m▄\x1b["
	  "0m\n"
	  "\x1b[48;2;142;96;41m "
	  "\x1b[48;2;139;95;41m\x1b[38;2;138;91;36m▄\x1b[48;2;140;96;45m\x1b[38;2;121;75;21m▄\x1b[48;2;"
	  "173;114;61m\x1b[38;2;121;70;16m▄\x1b[48;2;187;127;60m\x1b[38;2;152;85;30m▄\x1b[48;2;201;137;"
	  "70m\x1b[38;2;170;101;40m▄\x1b[48;2;211;143;77m\x1b[38;2;182;110;48m▄\x1b[48;2;218;144;"
	  "76m\x1b[38;2;191;115;50m▄\x1b[48;2;231;155;81m\x1b[38;2;194;116;47m▄\x1b[48;2;234;157;"
	  "81m\x1b[38;2;202;125;54m▄\x1b[48;2;225;146;67m\x1b[38;2;212;134;62m▄\x1b[48;2;209;131;"
	  "51m\x1b[38;2;215;138;67m▄\x1b[48;2;223;147;68m\x1b[38;2;202;123;65m▄\x1b[48;2;216;141;"
	  "69m\x1b[38;2;184;106;50m▄\x1b[48;2;194;120;58m\x1b[38;2;166;93;38m▄\x1b[48;2;183;111;"
	  "51m\x1b[38;2;152;80;27m▄\x1b[48;2;170;100;46m\x1b[38;2;162;91;36m▄\x1b[48;2;144;75;25m\x1b["
	  "38;2;226;152;94m▄\x1b[48;2;180;114;64m\x1b[38;2;209;137;80m▄\x1b[48;2;186;122;70m\x1b[38;2;"
	  "167;106;54m▄\x1b[48;2;146;95;49m\x1b[38;2;138;87;42m▄\x1b[48;2;110;70;27m\x1b[38;2;121;79;"
	  "37m▄\x1b[48;2;87;59;29m\x1b[38;2;128;84;47m▄\x1b[48;2;77;50;21m\x1b[38;2;90;59;26m▄\x1b[0m\n"
	  "\x1b[48;2;138;90;32m\x1b[38;2;170;119;60m▄\x1b[48;2;171;117;55m\x1b[38;2;203;140;68m▄\x1b["
	  "48;2;187;127;62m\x1b[38;2;231;156;82m▄\x1b[48;2;178;111;45m\x1b[38;2;251;173;95m▄\x1b[48;2;"
	  "188;111;47m\x1b[38;2;254;176;96m▄\x1b[48;2;163;82;21m\x1b[38;2;254;173;96m▄\x1b[48;2;174;92;"
	  "29m\x1b[38;2;251;167;92m▄\x1b[48;2;182;97;35m\x1b[38;2;252;161;89m▄\x1b[48;2;172;88;24m\x1b["
	  "38;2;242;158;85m▄\x1b[48;2;175;96;32m\x1b[38;2;242;155;82m▄\x1b[48;2;169;90;29m\x1b[38;2;"
	  "230;137;66m▄\x1b[48;2;167;89;29m\x1b[38;2;246;148;81m▄\x1b[48;2;164;86;27m\x1b[38;2;230;141;"
	  "72m▄\x1b[48;2;170;94;33m\x1b[38;2;246;173;101m▄\x1b[48;2;200;121;58m\x1b[38;2;255;182;"
	  "111m▄\x1b[48;2;219;139;76m\x1b[38;2;254;182;113m▄\x1b[48;2;237;157;91m\x1b[38;2;198;122;"
	  "63m▄\x1b[48;2;213;138;71m\x1b[38;2;174;108;55m▄\x1b[48;2;177;104;51m\x1b[38;2;146;89;"
	  "36m▄\x1b[48;2;159;102;51m\x1b[38;2;137;88;37m▄\x1b[48;2;133;84;38m\x1b[38;2;132;82;37m▄\x1b["
	  "48;2;129;83;39m\x1b[38;2;129;79;34m▄\x1b[48;2;135;86;43m\x1b[38;2;137;87;43m▄\x1b[48;2;139;"
	  "90;49m\x1b[38;2;150;98;54m▄\x1b[0m\n";
const char *raf_true_color_3
	= "\x1b[48;2;163;111;52m\x1b[38;2;149;98;40m▄\x1b[48;2;196;128;59m\x1b[38;2;177;118;49m▄\x1b["
	  "48;2;230;151;71m\x1b[38;2;206;134;59m▄\x1b[48;2;253;173;89m\x1b[38;2;226;148;67m▄\x1b[48;2;"
	  "254;176;93m\x1b[38;2;240;160;75m▄\x1b[48;2;254;179;97m\x1b[38;2;245;167;83m▄\x1b[48;2;255;"
	  "177;96m\x1b[38;2;247;167;83m▄\x1b[48;2;253;180;98m\x1b[38;2;243;158;79m▄\x1b[48;2;255;184;"
	  "102m\x1b[38;2;245;156;78m▄\x1b[48;2;254;184;104m\x1b[38;2;254;169;92m▄\x1b[48;2;255;180;"
	  "101m\x1b[38;2;253;169;93m▄\x1b[48;2;255;174;97m\x1b[38;2;253;166;91m▄\x1b[48;2;255;177;"
	  "99m\x1b[38;2;246;156;79m▄\x1b[48;2;250;174;93m\x1b[38;2;221;140;71m▄\x1b[48;2;224;147;"
	  "77m\x1b[38;2;191;119;65m▄\x1b[48;2;206;128;68m\x1b[38;2;155;94;48m▄\x1b[48;2;176;106;"
	  "59m\x1b[38;2;127;73;29m▄\x1b[48;2;147;91;44m\x1b[38;2;122;74;24m▄\x1b[48;2;129;78;29m\x1b["
	  "38;2;145;92;44m▄\x1b[48;2;134;83;35m\x1b[38;2;153;100;53m▄\x1b[48;2;140;88;44m\x1b[38;2;152;"
	  "101;54m▄\x1b[48;2;146;94;50m "
	  "\x1b[48;2;145;93;49m\x1b[38;2;144;93;50m▄\x1b[48;2;152;100;56m\x1b[38;2;135;85;43m▄\x1b[0m\n"
	  "\x1b[48;2;138;88;42m\x1b[38;2;137;91;40m▄\x1b[48;2;143;97;42m\x1b[38;2;132;86;35m▄\x1b[48;2;"
	  "167;111;50m\x1b[38;2;124;82;30m▄\x1b[48;2;185;120;55m\x1b[38;2;123;74;23m▄\x1b[48;2;212;134;"
	  "59m\x1b[38;2;130;80;30m▄\x1b[48;2;227;145;73m\x1b[38;2;137;87;40m▄\x1b[48;2;224;144;73m\x1b["
	  "38;2;135;83;38m▄\x1b[48;2;214;136;66m\x1b[38;2;124;79;34m▄\x1b[48;2;226;146;74m\x1b[38;2;"
	  "103;60;19m▄\x1b[48;2;237;151;79m\x1b[38;2;119;76;37m▄\x1b[48;2;222;135;63m\x1b[38;2;100;57;"
	  "19m▄\x1b[48;2;235;147;77m\x1b[38;2;97;59;20m▄\x1b[48;2;184;115;53m\x1b[38;2;76;44;6m▄\x1b["
	  "48;2;170;114;65m\x1b[38;2;91;53;19m▄\x1b[48;2;110;66;31m\x1b[38;2;113;65;25m▄\x1b[48;2;124;"
	  "74;29m\x1b[38;2;142;93;46m▄\x1b[48;2;132;80;34m\x1b[38;2;152;100;54m▄\x1b[48;2;155;101;"
	  "53m\x1b[38;2;150;96;51m▄\x1b[48;2;161;107;59m\x1b[38;2;146;92;46m▄\x1b[48;2;157;104;56m\x1b["
	  "38;2;155;101;55m▄\x1b[48;2;152;100;54m\x1b[38;2;154;102;58m▄\x1b[48;2;138;87;41m\x1b[38;2;"
	  "147;95;51m▄\x1b[48;2;131;82;40m\x1b[38;2;132;87;47m▄\x1b[48;2;128;82;42m\x1b[38;2;114;72;"
	  "34m▄\x1b[0m\n"
	  "\x1b[48;2;141;92;43m\x1b[38;2;144;93;44m▄\x1b[48;2;133;85;35m\x1b[38;2;144;93;44m▄\x1b[48;2;"
	  "129;82;31m\x1b[38;2;145;94;45m▄\x1b[48;2;131;83;34m\x1b[38;2;146;95;46m▄\x1b[48;2;127;79;"
	  "34m\x1b[38;2;147;96;47m▄\x1b[48;2;116;71;28m\x1b[38;2;146;97;49m▄\x1b[48;2;105;60;18m\x1b["
	  "38;2;136;87;40m▄\x1b[48;2;103;63;22m\x1b[38;2;134;87;42m▄\x1b[48;2;89;53;14m\x1b[38;2;133;"
	  "84;42m▄\x1b[48;2;74;39;6m\x1b[38;2;130;81;39m▄\x1b[48;2;87;52;17m\x1b[38;2;138;89;47m▄\x1b["
	  "48;2;81;43;4m\x1b[38;2;135;88;42m▄\x1b[48;2;108;66;26m\x1b[38;2;144;99;51m▄\x1b[48;2;130;84;"
	  "42m\x1b[38;2;147;100;52m▄\x1b[48;2;149;103;54m\x1b[38;2;147;97;53m▄\x1b[48;2;148;99;52m\x1b["
	  "38;2;142;93;46m▄\x1b[48;2;149;98;51m\x1b[38;2;135;86;39m▄\x1b[48;2;141;89;43m\x1b[38;2;139;"
	  "90;42m▄\x1b[48;2;148;97;50m\x1b[38;2;144;94;47m▄\x1b[48;2;156;104;58m\x1b[38;2;159;110;"
	  "62m▄\x1b[48;2;159;107;63m\x1b[38;2;151;101;56m▄\x1b[48;2;143;94;51m\x1b[38;2;135;87;"
	  "46m▄\x1b[48;2;122;83;43m\x1b[38;2;104;71;29m▄\x1b[48;2;104;68;35m\x1b[38;2;86;54;25m▄\x1b["
	  "0m\n";

const char *raf_ansi_1
	= "\x1b[48;5;0m          "
	  "\x1b[38;5;237m▄\x1b[48;5;0m\x1b[38;5;58m▄\x1b[48;5;137m\x1b[38;5;94m▄\x1b[48;5;173m\x1b[38;"
	  "5;130m▄\x1b[48;5;94m\x1b[38;5;131m▄\x1b[48;5;58m\x1b[38;5;94m▄\x1b[48;5;0m\x1b[38;5;"
	  "101m▄\x1b[48;5;0m       \x1b[0m\n"
	  "\x1b[48;5;0m        "
	  "\x1b[38;5;94m▄\x1b[48;5;58m\x1b[38;5;137m▄\x1b[48;5;179m\x1b[38;5;173m▄\x1b[48;5;173m\x1b["
	  "38;5;215m▄\x1b[48;5;215m\x1b[38;5;209m▄\x1b[48;5;215m\x1b[38;5;209m▄\x1b[48;5;173m  "
	  "\x1b[48;5;130m\x1b[38;5;137m▄\x1b[48;5;0m\x1b[38;5;130m▄\x1b[48;5;0m\x1b[38;5;208m▄\x1b[48;"
	  "5;0m     \x1b[0m\n"
	  "\x1b[48;5;0m     "
	  "\x1b[38;5;95m▄\x1b[48;5;95m\x1b[38;5;137m▄\x1b[48;5;137m\x1b[38;5;173m▄\x1b[48;5;94m\x1b[38;"
	  "5;130m▄\x1b[48;5;130m\x1b[38;5;137m▄\x1b[48;5;94m\x1b[38;5;137m▄\x1b[48;5;130m\x1b[38;5;"
	  "131m▄\x1b[48;5;173m \x1b[38;5;130m▄\x1b[48;5;94m \x1b[48;5;137m "
	  "\x1b[48;5;94m\x1b[38;5;173m▄\x1b[48;5;137m\x1b[38;5;173m▄\x1b[48;5;137m\x1b[38;5;130m▄\x1b["
	  "48;5;137m\x1b[38;5;94m▄\x1b[48;5;0m    \x1b[0m\n"
	  "\x1b[48;5;0m  "
	  "\x1b[38;5;95m▄\x1b[48;5;248m\x1b[38;5;94m▄\x1b[48;5;94m\x1b[38;5;130m▄\x1b[48;5;136m\x1b[38;"
	  "5;173m▄\x1b[48;5;173m   "
	  "\x1b[48;5;130m\x1b[38;5;173m▄\x1b[48;5;94m\x1b[38;5;136m▄\x1b[48;5;130m\x1b[38;5;215m▄\x1b["
	  "48;5;173m\x1b[38;5;209m▄\x1b[48;5;130m\x1b[38;5;172m▄\x1b[48;5;137m\x1b[38;5;173m▄\x1b[48;5;"
	  "173m    "
	  "\x1b[48;5;94m\x1b[38;5;130m▄\x1b[48;5;234m\x1b[38;5;95m▄\x1b[48;5;0m\x1b[38;5;58m▄\x1b[48;5;"
	  "0m  \x1b[0m\n"
	  "\x1b[48;5;0m\x1b[38;5;237m▄\x1b[48;5;95m\x1b[38;5;94m▄\x1b[48;5;94m\x1b[38;5;130m▄\x1b[48;5;"
	  "130m "
	  "\x1b[48;5;137m\x1b[38;5;136m▄\x1b[48;5;173m\x1b[38;5;137m▄\x1b[48;5;173m\x1b[38;5;136m▄\x1b["
	  "48;5;173m\x1b[38;5;137m▄\x1b[48;5;173m\x1b[38;5;137m▄\x1b[48;5;136m\x1b[38;5;179m▄\x1b[48;5;"
	  "179m\x1b[38;5;209m▄\x1b[48;5;215m  \x1b[48;5;173m \x1b[48;5;130m "
	  "\x1b[38;5;131m▄\x1b[48;5;173m  \x1b[48;5;137m "
	  "\x1b[48;5;130m\x1b[38;5;131m▄\x1b[48;5;95m\x1b[38;5;131m▄\x1b[48;5;58m\x1b[38;5;94m▄\x1b[48;"
	  "5;238m\x1b[38;5;58m▄\x1b[48;5;0m\x1b[38;5;58m▄\x1b[0m\n"
	  "\x1b[48;5;94m \x1b[48;5;130m    "
	  "\x1b[38;5;137m▄\x1b[48;5;136m\x1b[38;5;173m▄\x1b[48;5;137m\x1b[38;5;173m▄\x1b[48;5;130m "
	  "\x1b[48;5;52m\x1b[38;5;130m▄\x1b[48;5;94m\x1b[38;5;130m▄\x1b[48;5;173m\x1b[38;5;172m▄\x1b["
	  "48;5;166m\x1b[38;5;173m▄\x1b[48;5;52m\x1b[38;5;137m▄\x1b[48;5;95m\x1b[38;5;130m▄\x1b[48;5;"
	  "130m\x1b[38;5;137m▄\x1b[48;5;173m\x1b[38;5;137m▄\x1b[48;5;173m\x1b[38;5;130m▄\x1b[48;5;"
	  "137m\x1b[38;5;94m▄\x1b[48;5;131m\x1b[38;5;58m▄\x1b[48;5;131m\x1b[38;5;94m▄\x1b[48;5;94m\x1b["
	  "38;5;131m▄\x1b[48;5;239m\x1b[38;5;95m▄\x1b[48;5;94m \x1b[0m\n";
const char *raf_ansi_2
	= "\x1b[48;5;131m\x1b[38;5;94m▄\x1b[48;5;95m\x1b[38;5;52m▄\x1b[48;5;94m\x1b[38;5;58m▄\x1b[48;5;"
	  "94m\x1b[38;5;58m▄\x1b[48;5;130m\x1b[38;5;94m▄\x1b[48;5;130m\x1b[38;5;94m▄\x1b[48;5;137m\x1b["
	  "38;5;94m▄\x1b[48;5;137m\x1b[38;5;94m▄\x1b[48;5;130m \x1b[38;5;94m▄\x1b[48;5;172m "
	  "\x1b[48;5;173m "
	  "\x1b[38;5;172m▄\x1b[48;5;130m\x1b[38;5;173m▄\x1b[48;5;137m\x1b[38;5;173m▄\x1b[48;5;94m\x1b["
	  "38;5;215m▄\x1b[48;5;94m\x1b[38;5;173m▄\x1b[48;5;131m\x1b[38;5;137m▄\x1b[48;5;131m\x1b[38;5;"
	  "94m▄\x1b[48;5;95m\x1b[38;5;131m▄\x1b[48;5;94m\x1b[38;5;95m▄\x1b[48;5;94m\x1b[38;5;58m▄\x1b["
	  "48;5;94m\x1b[38;5;237m▄\x1b[48;5;58m\x1b[38;5;237m▄\x1b[0m\n"
	  "\x1b[48;5;94m   "
	  "\x1b[48;5;131m\x1b[38;5;94m▄\x1b[48;5;137m\x1b[38;5;94m▄\x1b[48;5;173m\x1b[38;5;130m▄\x1b["
	  "48;5;173m\x1b[38;5;131m▄\x1b[48;5;173m\x1b[38;5;131m▄\x1b[48;5;173m\x1b[38;5;136m▄\x1b[48;5;"
	  "179m\x1b[38;5;173m▄\x1b[48;5;173m   "
	  "\x1b[38;5;131m▄\x1b[48;5;137m\x1b[38;5;130m▄\x1b[48;5;131m\x1b[38;5;94m▄\x1b[48;5;130m "
	  "\x1b[48;5;94m\x1b[38;5;173m▄\x1b[48;5;131m\x1b[38;5;173m▄\x1b[48;5;137m\x1b[38;5;131m▄\x1b["
	  "48;5;95m\x1b[38;5;94m▄\x1b[48;5;58m\x1b[38;5;94m▄\x1b[48;5;237m\x1b[38;5;94m▄\x1b[48;5;"
	  "236m\x1b[38;5;237m▄\x1b[0m\n"
	  "\x1b[48;5;94m\x1b[38;5;137m▄\x1b[48;5;137m\x1b[38;5;173m▄\x1b[48;5;137m\x1b[38;5;179m▄\x1b["
	  "48;5;130m\x1b[38;5;215m▄\x1b[48;5;130m\x1b[38;5;215m▄\x1b[48;5;130m\x1b[38;5;215m▄\x1b[48;5;"
	  "130m\x1b[38;5;215m▄\x1b[48;5;130m\x1b[38;5;215m▄\x1b[48;5;130m\x1b[38;5;215m▄\x1b[48;5;"
	  "130m\x1b[38;5;209m▄\x1b[48;5;130m\x1b[38;5;173m▄\x1b[48;5;130m\x1b[38;5;209m▄\x1b[48;5;"
	  "130m\x1b[38;5;173m▄\x1b[48;5;130m\x1b[38;5;215m▄\x1b[48;5;173m\x1b[38;5;215m▄\x1b[48;5;"
	  "173m\x1b[38;5;215m▄\x1b[48;5;215m\x1b[38;5;173m▄\x1b[48;5;173m\x1b[38;5;131m▄\x1b[48;5;"
	  "131m\x1b[38;5;94m▄\x1b[48;5;131m\x1b[38;5;94m▄\x1b[48;5;94m   \x1b[48;5;95m \x1b[0m\n"
	  "\x1b[48;5;131m\x1b[38;5;94m▄\x1b[48;5;173m\x1b[38;5;137m▄\x1b[48;5;173m "
	  "\x1b[48;5;215m\x1b[38;5;173m▄\x1b[48;5;215m         "
	  "\x1b[38;5;173m▄\x1b[48;5;173m\x1b[38;5;137m▄\x1b[48;5;173m\x1b[38;5;95m▄\x1b[48;5;131m\x1b["
	  "38;5;94m▄\x1b[48;5;94m  \x1b[38;5;95m▄\x1b[48;5;94m\x1b[38;5;95m▄\x1b[48;5;95m  "
	  "\x1b[38;5;94m▄\x1b[0m\n"
	  "\x1b[48;5;94m  "
	  "\x1b[48;5;131m\x1b[38;5;94m▄\x1b[48;5;137m\x1b[38;5;94m▄\x1b[48;5;173m\x1b[38;5;94m▄\x1b[48;"
	  "5;173m\x1b[38;5;94m▄\x1b[48;5;173m\x1b[38;5;94m▄\x1b[48;5;173m\x1b[38;5;94m▄\x1b[48;5;"
	  "173m\x1b[38;5;58m▄\x1b[48;5;209m\x1b[38;5;94m▄\x1b[48;5;173m\x1b[38;5;58m▄\x1b[48;5;"
	  "173m\x1b[38;5;58m▄\x1b[48;5;131m\x1b[38;5;52m▄\x1b[48;5;131m\x1b[38;5;58m▄\x1b[48;5;58m "
	  "\x1b[48;5;94m \x1b[38;5;95m▄\x1b[48;5;95m "
	  "\x1b[48;5;131m\x1b[38;5;94m▄\x1b[48;5;131m\x1b[38;5;95m▄\x1b[48;5;95m "
	  "\x1b[48;5;94m\x1b[38;5;95m▄\x1b[48;5;94m \x1b[38;5;58m▄\x1b[0m\n"
	  "\x1b[48;5;94m     "
	  "\x1b[38;5;95m▄\x1b[48;5;58m\x1b[38;5;94m▄\x1b[48;5;58m\x1b[38;5;94m▄\x1b[48;5;58m\x1b[38;5;"
	  "94m▄\x1b[48;5;52m\x1b[38;5;94m▄\x1b[48;5;58m\x1b[38;5;94m▄\x1b[48;5;52m\x1b[38;5;94m▄\x1b["
	  "48;5;58m\x1b[38;5;95m▄\x1b[48;5;94m\x1b[38;5;95m▄\x1b[48;5;95m "
	  "\x1b[38;5;94m▄\x1b[48;5;95m\x1b[38;5;94m▄\x1b[48;5;94m "
	  "\x1b[48;5;95m\x1b[38;5;94m▄\x1b[48;5;131m "
	  "\x1b[38;5;95m▄\x1b[48;5;95m\x1b[38;5;94m▄\x1b[48;5;94m\x1b[38;5;58m▄\x1b[48;5;238m\x1b[38;5;"
	  "237m▄\x1b[0m\n";

void raf(bool true_color) {
	fraf(stdout, true_color);
}

void fraf(FILE *fp, bool true_color) {
	if (true_color) {
		fprintf(fp, "%s", raf_true_color_1);
		fprintf(fp, "%s", raf_true_color_2);
		fprintf(fp, "%s", raf_true_color_3);
	} else {
		fprintf(fp, "%s", raf_ansi_1);
		fprintf(fp, "%s", raf_ansi_2);
	}
}

static ssize_t looped_write(int fd, const char *str) {
	ssize_t len = strlen(str);
	ssize_t offset = 0;
	while (0 < len) {
		ssize_t written = write(fd, str + offset, len);
		if (written == -1)
			return -1;
		len -= written;
		offset += written;
	}

	return offset;
}

int fdraf(int fd, bool true_color) {
	if (true_color) {
		if (looped_write(fd, raf_true_color_1) == -1)
			return -1;
		if (looped_write(fd, raf_true_color_2) == -1)
			return -1;
		if (looped_write(fd, raf_true_color_3) == -1)
			return -1;
	} else {
		if (looped_write(fd, raf_ansi_1) == -1)
			return -1;
		if (looped_write(fd, raf_ansi_2) == -1)
			return -1;
	}

	return 0;
}
