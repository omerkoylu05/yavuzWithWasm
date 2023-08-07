#ifndef LIBCHESS_ZOBRIST_HPP
#define LIBCHESS_ZOBRIST_HPP

#include <cstdint>
#include "piece.hpp"
#include "side.hpp"
#include "square.hpp"
// #include "position.hpp"

namespace libchess::zobrist {

namespace {

constexpr std::uint64_t key_turn = 0x679ebe6f2ed869a4ULL;
constexpr std::uint64_t key_castling[4] = {
    0x6b63254b15e00a87ULL,
    0x098dc1575ddbd151ULL,
    0xdbb675f686df04a9ULL,
    0x71588a053b2bd9e5ULL,
};
constexpr std::uint64_t key_ep[8] = {
    0xa72780f845e9076dULL,
    0xfcc6f885b6c115dcULL,
    0x45b7a9a39104160cULL,
    0xfe71cfea4f444115ULL,
    0xe0d231bbdcc1441dULL,
    0xb6ba621251f6c0faULL,
    0xec9246215a2ae81cULL,
    0x40f734e63110b79dULL,
};
constexpr std::uint64_t key_piece[6 * 2 * 64] = {
    0xde0a6308c3df1559ULL, 0x2c4b06b9853875ccULL, 0x2ab7e75c55f58ce1ULL, 0xd870396170507503ULL, 0x2caea0c8b9204cb4ULL,
    0x945bed033f6e1d8dULL, 0xf76d7af05b02529bULL, 0x775d4b35eec039e6ULL, 0x53d5a48216a62191ULL, 0x243dec880916c9a9ULL,
    0x29fef5bc3455c011ULL, 0x30a3d546f5c6b927ULL, 0x551793f279293576ULL, 0x5a5fc4484265a753ULL, 0x445db7d8dba2c069ULL,
    0x937c8bd99ca1c50aULL, 0xeb93719dcfbba00dULL, 0xc0d0608adb6d182eULL, 0x68e46529607dfd18ULL, 0xfd24216411914bfbULL,
    0xa4b0ceecf129efe9ULL, 0x1edffbfc37a52313ULL, 0x0400fc06ad9d84e4ULL, 0x41f9a4b2e38bd7acULL, 0xe413d19abc020a69ULL,
    0x3c6cc1105099d2fdULL, 0x08c622a6f7979fbfULL, 0x6fd17a288e9033f9ULL, 0x276ed95bef692bd8ULL, 0xbab1280749265ab1ULL,
    0x521580a23473fa0cULL, 0x1348a1e5292355ccULL, 0x3b5a506552f073f2ULL, 0x27753e5c64796a2aULL, 0xe5461f6bbdcc55c4ULL,
    0x5fcee5f2b69aad6aULL, 0x09fb3f09c5e45acfULL, 0x1955cdb32cc2dab0ULL, 0x1b0e8cf6872c54e0ULL, 0x44a5d8e8b293aea3ULL,
    0x99e233e120f7a8ddULL, 0xf907d453c6a5eed0ULL, 0x00412511d58a34eeULL, 0x2f20f19f9e8c7258ULL, 0xded0ce51393b2a88ULL,
    0xe2a7fa30c77baf85ULL, 0xb7d8dd3d309ca6bdULL, 0xd0f5dc39eced3319ULL, 0x291f594b0a0c467eULL, 0x33d0202b0fb81011ULL,
    0xc575ee504ea6828dULL, 0xf0560e83a698b6a0ULL, 0x85dcdb8f9f9faf44ULL, 0x6ac00539848c1647ULL, 0x82554baa06da0c1fULL,
    0xd560908d9c4b2f8eULL, 0xfdac003e8b7448d4ULL, 0x72e20233a60f947eULL, 0x502683cc27256e50ULL, 0xdea0aed6bb56e567ULL,
    0xbdcd8ecd3511c55eULL, 0x2fc742759a0e6751ULL, 0xf58db0f1db2bdf2dULL, 0x90dd46bc490bd51fULL, 0x57409a63371c37ffULL,
    0xa7a6b1f65dc77f73ULL, 0x479f6ce9040fb9cbULL, 0xa84515f520a94558ULL, 0x052394929296b1d4ULL, 0xca5bc583cec4da5bULL,
    0xb081aa71ec1029e7ULL, 0xd33a58578df4d86fULL, 0x1d3dd82ef05aa17bULL, 0xa3cda58bb6f0b2c2ULL, 0x16ee1f4da8e23396ULL,
    0x41cb63e2998cbd3cULL, 0x5cd0cc06f6b92c6dULL, 0xff0fa192d8c51a3eULL, 0xdc055f76340c221aULL, 0x5239da00d95a5f50ULL,
    0x84810738fdeaf895ULL, 0xdee6a2a5b1c3d37dULL, 0xcc9925cf449f5262ULL, 0xc7869f3ced486357ULL, 0x2d0a398034ef56c1ULL,
    0x4b5fc15ccb97fac1ULL, 0xa31a1e8bb19cdcd3ULL, 0x197a8b5b09f480f9ULL, 0x6160aab861162402ULL, 0x962bbff97db3e4d5ULL,
    0xaba17daf285be057ULL, 0x031adae8cc315ed9ULL, 0xa7dbfe19b98e1ae6ULL, 0xabc758faf973ca27ULL, 0x889b9ece0c2bbf12ULL,
    0x08a0358547086667ULL, 0x056313222aa52493ULL, 0x418e116e9860db17ULL, 0xb37cc6ed57595f11ULL, 0x2a93f08028601c2cULL,
    0xec69162e1c52730dULL, 0xfcf4aabe9cc4e598ULL, 0xdcdf530f5cccb284ULL, 0x11c58334dc36e8b1ULL, 0xd20ef324aa6f99d9ULL,
    0x50263b867366fe32ULL, 0xa91abc8533f25a5fULL, 0xc13afb32a3e1a6f1ULL, 0x186ea08f5d72b286ULL, 0xf66e6cf906353567ULL,
    0xbbda2eb7fc298622ULL, 0x7839c0dc7d05f66cULL, 0x5312a4c8660e21c7ULL, 0x425804f982d474e5ULL, 0x8774611d032492fbULL,
    0x4e6abda74a855288ULL, 0x0c0376988958f099ULL, 0x59890eee41d21058ULL, 0xc28649fba75e4780ULL, 0x3eff41cfd4cf6af7ULL,
    0x8c0fed83f5bc42b8ULL, 0x12c74531bee537cbULL, 0xe52e7e177824609fULL, 0xf56229769f6fdde2ULL, 0x9c9e98914444cca1ULL,
    0x4fc95c151ab86f10ULL, 0x2848d7f8c593a00bULL, 0x9045fb8d27b80160ULL, 0x277cabb115f56d3bULL, 0xba44000bf51e616fULL,
    0x3534acd32b1a3bb9ULL, 0xfa306a6a4567b580ULL, 0xea688f7bf8ebdeb1ULL, 0x8fb42de86ebabbbeULL, 0xa55ac155576fb731ULL,
    0xf8fad3b61cefe815ULL, 0x2a4a832503d50e5cULL, 0xe00744421207b0c8ULL, 0x43527990b0ba4afdULL, 0x876331a98219b8a0ULL,
    0xc9c7befc262fa439ULL, 0x9e554b3e09c95517ULL, 0xb8bdf6e377a01fa5ULL, 0x4994e6fe75a1b854ULL, 0xbcfff32ddaa829d1ULL,
    0x9e8cf2034184fe81ULL, 0x4c8d40623ed84661ULL, 0x5a873656cca99353ULL, 0xbf878a875e8296a5ULL, 0xd5c0274bd5409c01ULL,
    0x1deda99d5eaf16bbULL, 0x4976a569f7525ae8ULL, 0x97300c9b71cee076ULL, 0x56357abeda7f6e3dULL, 0xd612f1d504b252beULL,
    0x7a7bca66bf923049ULL, 0xb2e45c7f8dcdc0e9ULL, 0x13c27573fac5b840ULL, 0xfbbc07dd2462a800ULL, 0x28e6908e266821ffULL,
    0x2d85a4bdf8d38850ULL, 0x481590bc66e08942ULL, 0x369d5c81f4933fc1ULL, 0x71ba13c2ba5accfeULL, 0x61272376a28f17beULL,
    0xb33bc28a8b37cbf8ULL, 0x1ba2573b675b19ceULL, 0x63a5670bf901bbe3ULL, 0x7e92e7f3716409d4ULL, 0xa6b22e3df82b924aULL,
    0xa930c2d56093c326ULL, 0x7320a9913060b405ULL, 0xf3612ed8fd8745f8ULL, 0x47b5a2df17403e86ULL, 0x57ae48ac7afefa3fULL,
    0x6c6f441842f25a06ULL, 0x1df11d3b20178d24ULL, 0x0d3a9bfab50ae4ebULL, 0xaea0c49755647c36ULL, 0xfec35c552f806b34ULL,
    0xbccaa5705daa0323ULL, 0x4a1d045df8937b9bULL, 0x4b1166ba9754bc25ULL, 0x1786e9d741d93c48ULL, 0x9a2170506cb82ca3ULL,
    0x22f78767fc469665ULL, 0x365961d0ce124969ULL, 0xf8cf363416f14c80ULL, 0x92eb0616ad95b9ceULL, 0x7baa9e3c375db510ULL,
    0x0512f8cb78565b32ULL, 0x2e8b3dd56ece5462ULL, 0x53ace9a06354333dULL, 0x7c3f03b00f2d7f34ULL, 0xf530672b08fe525bULL,
    0xfa914779e896ee17ULL, 0xa73b9e165d525a69ULL, 0x19a2afad7d29c413ULL, 0xece70c636a9cc882ULL, 0xa8c4727be719c6efULL,
    0x03c3d713344484d6ULL, 0x0bd7a88bee166cc5ULL, 0xe58689f1c1d16e5fULL, 0xfe749c67574bd51aULL, 0x22835c6c431832f6ULL,
    0x6cb73b75be66cd73ULL, 0x6a37cd10a652bf32ULL, 0x9bfd4b2c934889b1ULL, 0xa2462579ee71c41cULL, 0x4943a1d14ec57556ULL,
    0x7587d71467434ba1ULL, 0x6440cc4dd7a73f65ULL, 0x24d79e2959e182c0ULL, 0x71d8f2509fffd49aULL, 0x4afc2ae852f9be36ULL,
    0xcabaa13ffae3f2f6ULL, 0x632cd90e6be8cab6ULL, 0x11fa5f2941e753a7ULL, 0x5d0e5fa4c19a4323ULL, 0x155fc7180d42bdb6ULL,
    0x3866b00314de196dULL, 0x89020ecabe54961dULL, 0x0f7ab31189210bd7ULL, 0xcc51070169a91e4bULL, 0x1a120b691c895940ULL,
    0x8a5a3792f91796a6ULL, 0x8a9c45eae8c0435fULL, 0xe26dc2a80bbc9d7cULL, 0x0eed8fb4331d0d3bULL, 0xcca12a4d370ff104ULL,
    0x30d1fca41f6d5f61ULL, 0xd591f1e9adc48555ULL, 0xa5cc83f718a5d567ULL, 0x9199a9c9b62b403aULL, 0x8aa75e58d4769339ULL,
    0xe820a6db2ae3306aULL, 0xb92139dabd7f9b64ULL, 0x00a8d59d5fc07189ULL, 0xabf2ce3ecc479d5bULL, 0xe55f9f5eefa7c9c3ULL,
    0xbf65cd2aca7a22bdULL, 0x390796bfc88612f8ULL, 0x3be5d1ba97cada4aULL, 0xf8848047b9b052e1ULL, 0x1175d2409e455f81ULL,
    0x20c834b7b6a8289eULL, 0xe626bcdc21ed6bbaULL, 0x53d7647dd8d3b349ULL, 0xd80782c2c2127de8ULL, 0x35a586d4ef7d0e58ULL,
    0xf0b960820456a299ULL, 0x54eba2df8d720cc7ULL, 0x0b59ea0561ceda63ULL, 0x8260e1acf751ca2cULL, 0x03ab65fdecced8e6ULL,
    0xbb682613f7be18f9ULL, 0xf57561bda476bdbeULL, 0xcfb38074eebfac5dULL, 0xe81020237c50c7c9ULL, 0x0a9bd12ad018ae1fULL,
    0xa3c523218ee2a778ULL, 0x7ad3f5f701249494ULL, 0x338bee2ed6c52647ULL, 0x93c28b922034d228ULL, 0x8bd957fcc60271eaULL,
    0x2da4a013ddb276ddULL, 0x2e028e0ca912f5bbULL, 0xbba1ea419970b800ULL, 0xbd3d3b0a997c3d6bULL, 0x518453336955d5ecULL,
    0xcddec2391691142dULL, 0x9646479072e401f6ULL, 0x40c54cc93a5d3fe7ULL, 0x7a7fcb3b1cf269d1ULL, 0x6579b976d25c6a09ULL,
    0xca53d54342d79279ULL, 0xf07b3755c917427fULL, 0xcd02a1d3839c82c8ULL, 0xc4de5e81459be6b5ULL, 0xd639955d4d45c374ULL,
    0x5800b337b0b2c4efULL, 0x80d72804a2a5400bULL, 0xaea0f1b209b0da7aULL, 0xd0a237f43165a02cULL, 0xc841270f633eb061ULL,
    0x87e404d3ce0a7fcaULL, 0xd320efc83eed87f2ULL, 0xe58f8227e0535b65ULL, 0xc1b1313a0d220750ULL, 0x55ded55301391cf1ULL,
    0xc60a7b9189de2745ULL, 0x4dcf8bba1a23dc06ULL, 0x8434d63af6b8689dULL, 0x9a3828d7b0029a6dULL, 0x4e99cf4ea8394558ULL,
    0x5dad7cc62d435ba2ULL, 0xd02fb64609f3c5c6ULL, 0x60a4591e0640f9fcULL, 0x0b9725c11bd162f1ULL, 0xc1248e6d9f502607ULL,
    0xee403582dc60e6cdULL, 0x8491b8d227cdf680ULL, 0x664f708c016970f1ULL, 0xfa6e174fcd950618ULL, 0x48e555a919e06cfeULL,
    0xdf855567b3de7a23ULL, 0xd9fde3f301c02ebdULL, 0x4ea3fe9159bb832eULL, 0xa63fd78dc539e0c6ULL, 0xd821c0df49d365a3ULL,
    0xe7064c1ae9704f6aULL, 0x58a804bcc5aa5129ULL, 0xc5d9b733a449c222ULL, 0xaa40ce6ce610a3e1ULL, 0x15572a67e4923f2aULL,
    0x94c3f6280a4e4c35ULL, 0x327fa8e386e1f5f7ULL, 0x407e922598cfe65cULL, 0xccb2f7d8c62e37a7ULL, 0x0a4d150f3574b850ULL,
    0x2c8400f95f01f796ULL, 0xd7b4655f6f56e6dbULL, 0x041de2308d1fa30cULL, 0x868d5647858d4295ULL, 0xc1eab38028417162ULL,
    0x3c67e6f42f933292ULL, 0xfc5f4aa4c28cb5f7ULL, 0x8d5c298dc4d1a3f5ULL, 0x0003f19662e929c8ULL, 0xb55b7443588858b2ULL,
    0xf69c9f6beee3b206ULL, 0xfffe3e2dc976bc2eULL, 0xfbd62574c9939780ULL, 0xc18393220fa04c09ULL, 0xce863c683221119dULL,
    0x5cbdd826f3df5078ULL, 0x7e4296417934071cULL, 0x55d28a99b5a4767dULL, 0xfd24ba4aab55e9c3ULL, 0x90bbab439c8a6eabULL,
    0x59d3ba2a20ba9227ULL, 0x530d1add75a03a69ULL, 0xe0627ccebf6f606aULL, 0x399e273565600153ULL, 0xe7e8e23983cd2075ULL,
    0x359cf62093377fe7ULL, 0x9483cc6fdaa9726bULL, 0xe980ed0d9963355bULL, 0x1ac8b723c67f08f6ULL, 0xa188f5bf3d1c9f80ULL,
    0x1a72967fa8759f71ULL, 0x1473f664d0da4240ULL, 0xad58dd5040b4f4a9ULL, 0x0d9d71c7c179495fULL, 0xa2505d6875dc4cb4ULL,
    0x8b3b0136a96de034ULL, 0xd11c8add29d027deULL, 0xba8c2b44da4192d2ULL, 0xaf6ff13c42137f0aULL, 0x2a8d45c38ca34187ULL,
    0xf4160edfc598fc7fULL, 0x4b37b574dcbc7fa6ULL, 0xe10cc0d830f97049ULL, 0xade93176616fb9b8ULL, 0x14f481057edd819dULL,
    0x9375e75d6c1c3e18ULL, 0xff0b7077eff3a197ULL, 0xb76c2b5b4e1dacdaULL, 0xd90011954935572fULL, 0xa162e9f8a67c8f4aULL,
    0x15408bb360180971ULL, 0x1b5f45b607e10c70ULL, 0x9edca4c9e327dc1dULL, 0x3ce5daca961bf8d1ULL, 0xc2e9a3a594ec1e67ULL,
    0xca52a4596b4dbb0cULL, 0x8e0b77b7c6ab6284ULL, 0xd6320ec37b582316ULL, 0x7c0c62d7dec99195ULL, 0xc581b507dbc63427ULL,
    0x4ce7c79617aabcdcULL, 0x298b46e9921b76e1ULL, 0xde40bb7088d5e76fULL, 0xefcd248dda243cbcULL, 0x3eecea148e24a3e7ULL,
    0xefb5031b6f0242caULL, 0xff0437e26dc6aeeeULL, 0x9961d3cb80e2123aULL, 0x0e97f6bc8a865640ULL, 0x079807950487b80aULL,
    0xc7f56abcc47e40afULL, 0x4f96fd1b161c077fULL, 0xec29027276894a93ULL, 0xd912ff22c6d34c5bULL, 0x0ef749749b7f8f3aULL,
    0x07b1d2ed65d1baa0ULL, 0x5417ff732de59ccdULL, 0x85d5fb3d93e4b6b3ULL, 0x4e859f66c1e69a81ULL, 0xf53990440640a5ccULL,
    0x0b21e5d0bb4abde6ULL, 0x68b6d41f40fe6ee7ULL, 0x91fff371aa1bca06ULL, 0x1aa64991a1f52b74ULL, 0xa8bdcd2cc14594d2ULL,
    0x59ce83c21e33364eULL, 0x0f68733dd9319c3bULL, 0x0c14756f54d91a22ULL, 0xc9479c17569625feULL, 0x738374f4deec167bULL,
    0x0c8a9ee6b7330d99ULL, 0xb0462d091e3b6f4cULL, 0xd7a72dd5567fc3d3ULL, 0xa6315c4a2c633bc5ULL, 0x4efb12afe7381fa5ULL,
    0xe2a3c450d1274ff0ULL, 0x5668071dd838cd97ULL, 0x30fd489cbea4f667ULL, 0x27398d0e46c6a1c7ULL, 0x63013bd6a0122b0bULL,
    0x97ba83df1fd336f9ULL, 0x7ee1667548f49699ULL, 0xff88d09aeaad5043ULL, 0x4c586fde0afee2e5ULL, 0x25af5fb3057da27bULL,
    0xa71cb0df5a8151a0ULL, 0x09639eac4753a80bULL, 0x5517544e55e71815ULL, 0xaf74dd204b8ab294ULL, 0x396373bae01d0923ULL,
    0x1a377b9004a157b3ULL, 0xb23fd412c77f9ff9ULL, 0xd6f7603b7d7543f3ULL, 0x9a767105534ef75aULL, 0x2190657ab34a27e8ULL,
    0xbd6c5f3dd7a53689ULL, 0x5f29eff3faa50b5fULL, 0x7a9b448b84f844aeULL, 0xa4e843d3309d953cULL, 0xe4697f04c1219311ULL,
    0xf954ad4bfc242efbULL, 0x7b8bf95005013df3ULL, 0x83ed8ed953d6a103ULL, 0x2eb428cc49fec8deULL, 0x6b9b47a98a5a3885ULL,
    0xa86832a38078d50dULL, 0x00cc9c1dd00de014ULL, 0xb37276d030197e63ULL, 0xdde0bfed24b4c89bULL, 0xb077ec9b8c4bd535ULL,
    0xdc46984c0e8355d5ULL, 0x19931251ab89caf5ULL, 0xfcbcc65d40e50c8eULL, 0xecad2aad4a01e05fULL, 0xdf3263d0ccf43d16ULL,
    0xb9334b27833ae3e3ULL, 0x71c03ac239d0a60eULL, 0x0ad3ef0015646024ULL, 0xb27bd94d0ac34e50ULL, 0x4a27c72794ddcb18ULL,
    0x69a929607c573ab5ULL, 0x81edd6048be36593ULL, 0x6cbd777080a1fd95ULL, 0x22bcdc3776319dd8ULL, 0x1a36268987666621ULL,
    0x18fd52051eb1f67aULL, 0xefe68a58ae9d9c1dULL, 0x6e3a8ad92c15cbe3ULL, 0x15bed59a04ecac79ULL, 0xe579f953499ba6a0ULL,
    0x19304ca2d59f9e76ULL, 0xcc01166c500123b1ULL, 0x0d1ec169097667caULL, 0xa4fc7136277b52a1ULL, 0xbdae279581c25707ULL,
    0x371dc4b08ea2283fULL, 0x6556ea02401b3eabULL, 0x76761b73acdcc1b7ULL, 0x6bffc3425fa6e143ULL, 0x417e47ab78249914ULL,
    0xc5e8a1628830da3eULL, 0x9e1d5ae46026a240ULL, 0x8585b6e6ecc18c04ULL, 0xb7c276a6f8d4f727ULL, 0xc629e69414dd985bULL,
    0x3ef96d61007f4150ULL, 0x15b2ef71b68e6721ULL, 0xc7a980f7c7daf6bdULL, 0x2d88e74fad9a43beULL, 0x9f9abbb7881462c5ULL,
    0x2a6c7a5c082a6f10ULL, 0x24495f34e83fc154ULL, 0x487aaeba2c86583eULL, 0x0e4208f91505b2f4ULL, 0xd7f116f6da7841edULL,
    0x426c580474443075ULL, 0x9ddf2a20fb3898d0ULL, 0x87401b7168785ecbULL, 0x08ff3f19b4088872ULL, 0xed1d9d4830b8eac4ULL,
    0x8d6848c6a6d5bffaULL, 0xcca02304f4a01d38ULL, 0x09febdda8cebb0cfULL, 0xfbed956113cf3dadULL, 0x39f00b5bf8cdf00bULL,
    0x25e5e967b0b48e25ULL, 0xa547eb8ec098bb4dULL, 0x64b6f5111290c19fULL, 0xb83392b47960c693ULL, 0x8062b38b100a585fULL,
    0x134e46c18de6a802ULL, 0x0ce120776a2fa4b8ULL, 0xb814257f90aaa343ULL, 0x7d686aeb364bfdafULL, 0x467e51db8904af88ULL,
    0x4d858ea596ff4d5eULL, 0xd1f54093fb4fbf7aULL, 0xd39091a5475fb283ULL, 0xc0d158f53bb37c26ULL, 0xe4d15a6232beb581ULL,
    0x47f420736fe19fb5ULL, 0xa28c9a74d4ef6bf1ULL, 0xec21ffc36aafb904ULL, 0x8ecf254d9c7fef9bULL, 0x0ddd174e617c6286ULL,
    0xc4639a1d172deac7ULL, 0x5be20db2b07f8832ULL, 0x596eb390bd48167eULL, 0xd0d3ea73762e5326ULL, 0x64c65103ea795380ULL,
    0x7c0d1747a743b55eULL, 0x62ccce608eeaec1cULL, 0x8572bca03f818b5fULL, 0x3c4e8a8eb433fbeaULL, 0x92efc16ae9375ea1ULL,
    0x6ab05c37ff5b6104ULL, 0xed0226dff754d76eULL, 0x42b060ee56987d72ULL, 0x9635d344129670fbULL, 0x349fe117bdc8021cULL,
    0x1b189413810bc189ULL, 0x2bb0b158c66ecbdbULL, 0x5cc31c1be60c1352ULL, 0x50ed94f9c3b52319ULL, 0x87336068b7331136ULL,
    0x5c5a8e907fcbd71dULL, 0x53cf4234d125697aULL, 0xb5a8affd794b38a4ULL, 0xc520bd9a710bc2feULL, 0x4102bbbcfbfebe37ULL,
    0x5f5ff3ace9e2399aULL, 0x12c822e31299bfd4ULL, 0x3e6130e356039eb4ULL, 0xfbf8a690e17bc97bULL, 0x0d155c83651db210ULL,
    0x6af4992d6c96f8edULL, 0x8282132f3f9e252eULL, 0x8b42c6d3fd3acdd9ULL, 0x51bb2061c34731fbULL, 0xb6bdaf1ed3484586ULL,
    0x1b29fa041dd9e5f6ULL, 0x54d88c47d32530bdULL, 0xfc172b4a31ac4dd3ULL, 0x7c603b4122d45245ULL, 0x37b8ea2e4e5117b8ULL,
    0xac4d53ee5f331b03ULL, 0x5f3a932fa72c9088ULL, 0x1316eeb5fea07afdULL, 0x8726fc543fc49921ULL, 0xcce5222414561e75ULL,
    0x39d6ed6e181c9c1fULL, 0x1ee13e06b29bddc7ULL, 0x999036e7f7c9cc5cULL, 0x130395eb83ea99deULL, 0xf19e7a83adc3727eULL,
    0xb31bdbc7535f153eULL, 0x68d785ad6b4c33f8ULL, 0x3103baf6285d7f7aULL, 0x0380e015d47704eaULL, 0xb406b34e7cb0367bULL,
    0xdebc071c5027ff76ULL, 0xd76c4ea1e083bce6ULL, 0x3b499716ceabde7cULL, 0x4f14a762c45f05d7ULL, 0xda075cea70851c75ULL,
    0xa39afe2326615a8cULL, 0x18d9584fb3aec6dbULL, 0x445306a5e72a11f7ULL, 0x9186367d9e5f7f0bULL, 0xf96783cc08a31d1aULL,
    0xb891f72427114478ULL, 0x2ac2c30dcaceca43ULL, 0x221c38f54ee89d29ULL, 0xa069e86ae1960942ULL, 0x7e62f6ee19ebf863ULL,
    0x695d268489364249ULL, 0xcee343224ff091a2ULL, 0x33bd4c48cf59e7dcULL, 0x4e88b2ed39d5bd95ULL, 0x5f847057d6a41dc0ULL,
    0x974cc3c8218d2bdbULL, 0xdd7458f9f23298feULL, 0x128b7764c916baf3ULL, 0x6a3ebd11711c3b9eULL, 0xc848c73ea1d8a782ULL,
    0x6c6b278e676c7986ULL, 0x79645ec37a7094dbULL, 0xe8433dc7186544b8ULL, 0x8a0dfa9c27fa7967ULL, 0x73c976f4f7a9571aULL,
    0x79585ee1bb500634ULL, 0x50c1f96ee52ffdbbULL, 0x3e00feaaa5fb320cULL, 0xcb16ca735f780748ULL, 0x65d40ecdd0436093ULL,
    0x4affc5ccecb7d887ULL, 0xa21521f6d2f1f7eaULL, 0xa50afd9fe4f1d116ULL, 0x225e8c6188709051ULL, 0x88c301490d90e6b3ULL,
    0x0ab71b8ad1e595f4ULL, 0x7ccb17391364b1cdULL, 0x7e0a9a300cd77238ULL, 0x4cc14d1db7413b83ULL, 0x95aabd0016fac304ULL,
    0xd6068dfc3d0d767dULL, 0x857f02eb31170cc5ULL, 0xe518971f6f14f9a9ULL, 0xe05b8955d5652c8bULL, 0x1942b19774ab1e0aULL,
    0x8f2d942c7988e001ULL, 0x1bd6dedf5d28e019ULL, 0xa428659961ca71dfULL, 0xe4ac514ad3b1a978ULL, 0x6d9ba0ac46c66568ULL,
    0x93dadda43bb5819cULL, 0x0e6de94844297cd4ULL, 0xfa67f264206a0f7fULL, 0x8cc86c6445d6ff38ULL, 0x2ef740e2c15f8e5dULL,
    0xb8b404dedffade2aULL, 0x4ef727852fc4f33fULL, 0xd82eb1b97d1a7d12ULL, 0xcf136722023896bfULL, 0x413fe80f1c5cb769ULL,
    0x51a19301235ce1f4ULL, 0xa7fb72d34c9785f7ULL, 0x1752a7165d692d83ULL, 0x7862798cf9e90a5bULL, 0x04a06a8f1515b7f6ULL,
    0x378e9a09b1ef2d41ULL, 0xe8c5bb6e320bbfc0ULL, 0xedb6749c35a04c20ULL, 0xb8ff15fa41ede6fbULL, 0xb1aa98c8f9c24d59ULL,
    0xe28f80297aacb175ULL, 0x657b2ffe6473ee60ULL, 0xc0ca52ba31ede93eULL, 0xf16c88bc0399721dULL, 0x93c31c169abe92e0ULL,
    0x230baccd91b9802cULL, 0x493794c638810da9ULL, 0x942c7078269ab247ULL, 0x182d71ebe7e171a5ULL, 0x3cda5c7eab7dd58cULL,
    0x420378945af3bf32ULL, 0x2392cc597bd91bbfULL, 0x66f8134245e1da52ULL, 0x56db05c27ba9fad9ULL, 0xc83bc18551d6ccefULL,
    0x40ff0c2330ec02f6ULL, 0x162cb6c9bcd3b537ULL, 0x6d266a2246478673ULL, 0x25fa80e43d6741f0ULL, 0x905f1a9b008bf9eaULL,
    0x9b72080084efbffdULL, 0x6585773107a050f7ULL, 0xe532c358b9ee9b56ULL, 0x32a7d248e5209918ULL, 0xf92be566d5a12e86ULL,
    0x65f697d206d1d573ULL, 0xc9b5f97b3525ba40ULL, 0x8390615508632d39ULL, 0xb75779a0ce95df96ULL, 0x371110370016dce6ULL,
    0x47d9d3d79039717eULL, 0x93789dc7ddd4b4b1ULL, 0x89e347e228d1f525ULL, 0x9de90d9002502e42ULL, 0x6fd53ca7112c82ceULL,
    0xd46b66866b2589c1ULL, 0x15d5e0baccbdef61ULL, 0x72a2c0924843554aULL, 0x93b565f782e6ed29ULL, 0x6a2b35ddaeef25cbULL,
    0xa53a5cad65e57ea4ULL, 0xda05cf68eb043ab1ULL, 0x77cb397f4090306cULL, 0x1996ab63a3a3b80eULL, 0x44be46877617d0b2ULL,
    0x153b472d685b0d51ULL, 0xe995db9b256ace0dULL, 0x564f383ccf56fd8fULL, 0x15fb845ee884b83cULL, 0xf8222c491cb444f3ULL,
    0x3048f70c6d38600dULL, 0x262a7f9103587873ULL, 0x527f416d0101a35dULL, 0x89d593e9bd2ce816ULL, 0xaf7f04d18aa7ddaeULL,
    0x050d3e344aaa9744ULL, 0xd33dd2b82f181ca0ULL, 0xde9c6f2ea4eba285ULL, 0xd85a8a851d0381cdULL, 0x7d412b4c7cf89c63ULL,
    0xef8b9c129af4fbd8ULL, 0xde0ec89028c1ecc7ULL, 0x2101c84487b47535ULL, 0x937b98f2d26c737eULL, 0x8768b45d7b7f4694ULL,
    0x0fe4c3921ca17cc5ULL, 0x83226fe49f24d4c3ULL, 0x950a8be82edddba8ULL, 0x0a184c5253205f76ULL, 0xc61ff7e4ec001739ULL,
    0x403882a9c08e9fdaULL, 0xd9d4c3b8b4f15806ULL, 0xa560ff75bb942c84ULL, 0x2dfe08a2cd3a4d50ULL, 0xba177d16de77dd68ULL,
    0x7de18d41f8c461f4ULL, 0xc51630637cff9639ULL, 0x6f3dce62962aec0dULL, 0x445b99cbe96cc03cULL, 0x250fa937eda6fdc8ULL,
    0x4a4fa3a418480145ULL, 0x244bf770fd27e8abULL, 0xb83174cf13adad46ULL, 0xcf785174801d6e7bULL, 0xea53a30d5f4dff85ULL,
    0xc4f6bb28deee7e0bULL, 0xbcd05ff3713b04c2ULL, 0xe7f50cb64b2f7b95ULL, 0xf9e15699f4dd4058ULL, 0x01dbba1224c79bd1ULL,
    0x8ce0a9606486da62ULL, 0xb783b974ff57a947ULL, 0xd375ab531563adf0ULL, 0xb50aa6412c99963dULL, 0x211e691d4ebd012dULL,
    0xd98c4eabe74e5d8bULL, 0xb60e6292d20e2e95ULL, 0xb02ec07ac159040eULL, 0x7d5685f72a1f8867ULL, 0xb1d20051f4985e5cULL,
    0x32c66436f7e0423cULL, 0x1d8f9f4abd50aa77ULL, 0xaa7f44afb9ce05a7ULL, 0x59435d516f12fba5ULL, 0x73b2a84ebd34e306ULL,
    0x2c44e2911b14e9a4ULL, 0xed2ce4dd8d8d9858ULL, 0x72b7d88bd1b9660fULL, 0x6c1e57555e40abe6ULL, 0xb8a183dca03d4622ULL,
    0xe1f20c6145f85fe4ULL, 0x450a87aba3167ee7ULL, 0x677524f27efe26feULL,
};

}  // namespace

[[nodiscard]] constexpr std::uint64_t turn_key() {
    return key_turn;
}

[[nodiscard]] constexpr std::uint64_t castling_key(const int t) {
    return key_castling[static_cast<int>(t)];
}

[[nodiscard]] constexpr std::uint64_t piece_key(const Piece p, const Side s, const Square sq) {
    return key_piece[64 * 2 * static_cast<int>(p) + 64 * static_cast<int>(s) + static_cast<int>(sq)];
}

[[nodiscard]] constexpr std::uint64_t ep_key(const int p) {
    return key_ep[p];
}

}  // namespace libchess::zobrist

#endif
