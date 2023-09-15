--- sys/dev/virtio/9pfs/virtfs_vnops.c.orig	2022-03-23 13:18:44 UTC
+++ sys/dev/virtio/9pfs/virtfs_vnops.c
@@ -285,7 +285,9 @@ virtfs_lookup(struct vop_lookup_args *ap)
 			error = VOP_ACCESS(dvp, VWRITE, cnp->cn_cred,
 			    curthread);
 			if (!error) {
+#if __FreeBSD_version < 1400068
 				cnp->cn_flags |= SAVENAME;
+#endif
 				return (EJUSTRETURN);
 			}
 		}
@@ -304,8 +306,10 @@ virtfs_lookup(struct vop_lookup_args *ap)
 		/* Check if the entry in cache is stale or not */
 		if ((virtfs_node_cmp(vp, &newfid->qid) == 0) &&
 		    ((error = VOP_GETATTR(vp, &vattr, cnp->cn_cred)) == 0)) {
+#if __FreeBSD_version < 1400068
 			if (cnp->cn_nameiop != LOOKUP && (flags & ISLASTCN))
 				cnp->cn_flags |= SAVENAME;
+#endif
 			goto out;
 		}
 		/*
@@ -439,8 +443,10 @@ virtfs_lookup(struct vop_lookup_args *ap)
 
 	cnp->cn_nameptr[cnp->cn_namelen] = tmpchr;
 
+#if __FreeBSD_version < 1400068
 	if (cnp->cn_nameiop != LOOKUP && (flags & ISLASTCN))
 		cnp->cn_flags |= SAVENAME;
+#endif
 
 	/* Store the result the cache if MAKEENTRY is specified in flags */
 	if ((cnp->cn_flags & MAKEENTRY) != 0)
@@ -2150,4 +2156,4 @@ VFS_VOP_VECTOR_REGISTER(virtfs_vnops);
 };
 #if __FreeBSD_version >= 1300069
 VFS_VOP_VECTOR_REGISTER(virtfs_vnops);
-#endif
\ No newline at end of file
+#endif
