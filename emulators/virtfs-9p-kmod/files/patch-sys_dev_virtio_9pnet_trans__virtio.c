--- sys/dev/virtio/9pnet/trans_virtio.c.orig	2022-03-23 13:18:44 UTC
+++ sys/dev/virtio/9pnet/trans_virtio.c
@@ -502,7 +502,12 @@ vt9p_modevent(module_t mod, int type, void *unused)
 	return (error);
 }
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(vt9p, virtio_pci, vt9p_drv,
+    vt9p_modevent, 0);
+#else
 DRIVER_MODULE(vt9p, virtio_pci, vt9p_drv, vt9p_class,
     vt9p_modevent, 0);
+#endif
 MODULE_VERSION(vt9p, 1);
 MODULE_DEPEND(vt9p, virtio, 1, 1, 1);
