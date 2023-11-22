--- sys/dev/virtio/9pnet/trans_virtio.c.orig	2022-03-23 13:18:44 UTC
+++ sys/dev/virtio/9pnet/trans_virtio.c
@@ -240,7 +240,11 @@ vt9p_alloc_virtqueue(struct vt9p_softc *sc)
 	    vt9p_intr_complete, sc, &sc->vt9p_vq,
 	    "%s request", device_get_nameunit(dev));
 
+#if __FreeBSD_version >= 1500001
+	return (virtio_alloc_virtqueues(dev, 1, &vq_info));
+#else
 	return (virtio_alloc_virtqueues(dev, 0, 1, &vq_info));
+#endif
 }
 
 /* Probe for existence of 9P virtio channels */
@@ -502,7 +506,12 @@ vt9p_modevent(module_t mod, int type, void *unused)
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
