PORTNAME=	virtfs-9p-kmod
PORTVERSION=	g2022030300
CATEGORIES=	emulators

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Virtfs-9p kernel module
WWW=		https://github.com/swills/virtfs-9p-kmod

USES=		kmod

USE_GITHUB=	yes
GH_ACCOUNT=	swills
GH_TAGNAME=	572734c

MAKE_ARGS=	CWARNFLAGS="-Wno-format -Wno-error"
CFLAGS=		-I${WRKSRC}/sys

PLIST_FILES=	${KMODDIR}/virtio_9pnet.ko \
		${KMODDIR}/virtio_9pfs.ko

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=     only supported on FreeBSD
.endif

do-build:
	cd ${WRKSRC}/sys/modules/virtio/9pnet && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS:N${DESTDIRNAME}=*}
	cd ${WRKSRC}/sys/modules/virtio/9pfs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS:N${DESTDIRNAME}=*}

do-install:
	${INSTALL_KLD} ${WRKSRC}/sys/modules/virtio/9pnet/virtio_9pnet.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_KLD} ${WRKSRC}/sys/modules/virtio/9pfs/virtio_9pfs.ko ${STAGEDIR}${KMODDIR}

.include <bsd.port.mk>
